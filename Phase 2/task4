
#include<iostream>
#include<vector>
#include<climits>
#include<string>
#include<thread>
#include<algorithm>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/wait.h>

#define MSG_KEY 1234

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

struct msg_buffer {
    long msg_type;
    int size;
    int data[1000];
    int sum;
};

void findSum(int arr[], int& size, int& sum) {
	for(int i = 0; i < size; i++) {
		sum = sum + arr[i];
	}
}

void client(vector<Surgery>& surgeries, int msgid) {
    msg_buffer message;

    message.msg_type = 1;
    message.size = surgeries.size();
    msgsnd(msgid, &message, sizeof(message),0);
    cout << "client send size : "<< message.size <<endl;

    message.msg_type = 2;
    for (int i = 0; i < message.size; i++) {
        message.data[i] = surgeries[i].getDuration();
    }
    msgsnd(msgid, &message, sizeof(message.data), 0);
    cout << "Client Sent durations: ";
    for(int i = 0; i<message.size; i++) {
		cout << " "<<message.data[i] << " ";
	}
	cout << endl;

    msgrcv(msgid, &message, sizeof(message), 3, 0);
     int sum = message.sum;

    cout << "Total sum in client side sent from server : " << sum << endl;
}

void server(int msgid) {

    msg_buffer message;

    msgrcv(msgid, &message,sizeof(message),1,0);
    cout << "server received size : "<< message.size <<endl;

    msgrcv(msgid, &message, sizeof(message.data), 2, 0);
	cout << "new array created in server : ";
    for(int i = 0; i<message.size; i++){
		cout << " "<<message.data[i] << " ";
	}
    cout <<endl;
    int sum = 0;
    findSum(message.data, sum, message.size);

    message.msg_type = 3;
    message.sum = sum;
    msgsnd(msgid, &message, sizeof(message), 0);
    cout << "Sum sent to client : " << message.sum << endl;
}

int main() {
    vector<Surgery> surgeries {
            Surgery("S001", 3),
            Surgery("S002", 10),
            Surgery("S003", 5),
            Surgery("S004", 12),
            Surgery("S005", 6)
        };

    int msgid = msgget(MSG_KEY, 0666 | IPC_CREAT);

    pid_t pid = -1;
    {
        pid = fork();
        if (pid == 0) {
        client(surgeries, msgid);
        return 0;
        }
    }
    {
        pid = fork();
        if (pid == 0) {
        server(msgid);
        return 0;
        }
    }

    wait(nullptr);

    msgctl(msgid, IPC_RMID, nullptr);

    return 0;
}
