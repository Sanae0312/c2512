#include <iostream>
#include <vector>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <cstring>
#include <string>
#include <unistd.h>

using namespace std;

class Surgery {
private:
    string surgeryId;
    int Duration;

public:
    Surgery(string surgeryId, int Duration) : surgeryId(surgeryId), Duration(Duration) {}

    int getDuration() {
        return Duration;
    }
};

struct Message {
    long msg_type;
    int data[100];
};

void client(int msgid) {
    vector<Surgery> surgeries {
            Surgery("S001", 3),
            Surgery("S002", 10),
            Surgery("S003", 5),
            Surgery("S004", 12),
            Surgery("S005", 6)
        };

    int size = surgeries.size();
    Message msg;
    msg.msg_type = 1;

    for (int i = 0; i < size; ++i) {
        msg.data[i] = surgeries[i].getDuration();
    }

    cout << "Client sending durations: ";
    for (int i = 0; i < size; ++i) {
        cout << msg.data[i] << " ";
    }
    cout << endl;

    msgsnd(msgid, &msg, sizeof(msg.data), 0);

    int sum;
    msgrcv(msgid, &msg, sizeof(msg.data), 2, 0);
    sum = msg.data[0];
    cout << "Client received sum from server: " << sum << endl;
}

void server(int msgid) {
    Message msg;
    int sum = 0;

    msgrcv(msgid, &msg, sizeof(msg.data), 1, 0);

    cout << "Server received durations: ";
    for (int i = 0; i < 5; ++i) {
        cout << msg.data[i] << " ";
        sum += msg.data[i];
    }
    cout << endl;

    cout << "Server calculated sum: " << sum << endl;

    msg.msg_type = 2;
    msg.data[0] = sum;
    msgsnd(msgid, &msg, sizeof(msg.data), 0);
}

int main() {
    int msgid = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("Message queue creation failed");
        return 1;
    }
    {
        int pid = fork();
        if (pid == 0) {
            client(msgid);
            return 0;
        }
    }
    
    {
        int pid = fork();
        if (pid == 0) {
            server(msgid);
            return 0;
        }
    }
    wait(nullptr);
    wait(nullptr);

    msgctl(msgid, IPC_RMID, nullptr);
    return 0;
}
