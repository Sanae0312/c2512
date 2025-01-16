#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <unistd.h>
#include <climits>
#include <algorithm>

using namespace std;

class Surgery {
	private:
		string surgeryId;
		int Duration;
	public:
		Surgery(string surgeryId, int Duration) : surgeryId(surgeryId), Duration(Duration) {}
		//string GetSurgeryID();
        int getDuration() {
	        return Duration;
        }
};

void findSum(int arr[], int& size, int& sum) {
	for(int i = 0; i < 5; i++) {
		sum = sum + arr[i];
	}
}

void client(vector<Surgery>& surgeries, int& write_end1, int& read_end2) {
    int size = surgeries.size();
    write(write_end1, &size, sizeof(size));
    int durations[size];
    for(int i = 0; i < surgeries.size(); i++) {
        durations[i] = surgeries[i].getDuration();
    }
    write(write_end1, durations, sizeof(durations));
    cout << "client sending: ";
    for(int i = 0; i < size; i++) {
        cout << durations[i] << " ";
    }
    cout << endl;
    close(write_end1);
    int sum =0;
    read(read_end2, &sum, sizeof(int));
    cout << "Sum of surgeries is: " << sum << endl;
    close(read_end2);
}

void server(int& read_end1, int& write_end2) {
    int size;
    read(read_end1, &size, sizeof(size));
    int arr[size];
    read(read_end1, arr, sizeof(int)*size);
    cout << "Server recieved: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    close(read_end1);
    int result = 0;
    findSum(arr,size,result);
    write(write_end2, &result, sizeof(result));
    cout << "Sum sent: " << result << endl;
    close(write_end2);
}

int main() {
    vector<Surgery> surgeries {
            Surgery("S001", 3),
            Surgery("S002", 10),
            Surgery("S003", 5),
            Surgery("S004", 12),
            Surgery("S005", 6)
        };

    int pipe_fd1[2];
    int pipe_fd2[2];
    if(pipe(pipe_fd1) == -1) {
        perror("pipe");
        cout << "Pipe not created" << endl;
        return 1;
    }
    if(pipe(pipe_fd2) == -1) {
        perror("pipe");
        cout << "Pipe not created" << endl;
        return 1;
    }

    int& read_end1 = pipe_fd1[0];
    int& write_end1 = pipe_fd1[1];
    int& read_end2 = pipe_fd2[0];
    int& write_end2 = pipe_fd2[1];

    pid_t pid = -1;
    {
        pid = fork();
        if(pid == 0) {
            close(read_end1);
            client(surgeries, write_end1, read_end2);
            return 0;
        }
    }
    {

        pid = fork();
        if(pid == 0) {
            close(write_end1);
            server(read_end1, write_end2);
            return 0;
        }
    }
        return 0;
}
