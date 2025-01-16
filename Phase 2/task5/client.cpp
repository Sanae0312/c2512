#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <fcntl.h>
#include <cstring>
#include <unistd.h>
#include <vector>

using namespace std;

class Surgery{
	private:
		string surgeryId;
		int Duration;
	public:
		Surgery(string surgeryId, int Duration){
			this -> surgeryId = surgeryId;
			this -> Duration = Duration;
		}

		int getDuration() { 
            return this -> Duration; };

};

int main(){
	vector<Surgery> surgeries {
            Surgery("S001", 3),
            Surgery("S002", 10),
            Surgery("S003", 5),
            Surgery("S004", 12),
            Surgery("S005", 6)
        };

	int dur[surgeries.size()] = {0};
	
	for(int i = 0; i < surgeries.size(); i++){
		dur[i] = surgeries[i].getDuration();
	}

	
	int numOfElements = vec.size();

	const char* pipe1 = "pipe1";
	const char* pipe2 = "pipe2";
	int pipe_two_read_fd, pipe_one_write_fd;
	pipe_one_write_fd = open(pipe1, O_WRONLY);
	pipe_two_read_fd = open(pipe2, O_RDONLY);
        
	if(pipe_one_write_fd == -1){
		perror("pipe1 open failure at client");
		return 1;
	}
	if(pipe_two_read_fd == -1){
		perror("pipe2 open failure at client");
		return 1;
	}

	write(pipe_one_write_fd, &numOfElements, sizeof(int));
	cout << "Client sent number of elements: " << numOfElements << endl ;

	write(pipe_one_write_fd, dur, sizeof(dur));
	cout << "Client sent dur : ";
	for(int dose:dur){
		cout << dose << "\t";
	}
	cout << endl;
	close(pipe_one_write_fd);

	sleep(1);

	int sum;
	read(pipe_two_read_fd, &sum, sizeof(int));
	cout << "sum received from server: " << sum << endl;

	close(pipe_two_read_fd);
	

	return 0;
}
