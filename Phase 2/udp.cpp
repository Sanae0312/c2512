
#include <iostream>
#include <vector>
#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

using namespace std;

class Surgery {
private:
    string SurgeryId;
    int Duration;
public:
    Surgery(string SurgeryId, int Duration) : SurgeryId(SurgeryId), Duration(Duration) {}

    string getSurgery() const {
        return SurgeryId; 
    }
    int getDuration() const { 
        return Duration; 
    }
};

void server(int port);
void serveClient(int& server_socket_fd, sockaddr_in& client_address);
void client(string server_ip, int port);
void sendSurgeryData(int& client_socket_fd, sockaddr_in& server_address);

void server(int port) {
    int server_socket_fd;
    if ((server_socket_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    if (bind(server_socket_fd, (sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        close(server_socket_fd);
        exit(EXIT_FAILURE);
    }

    sockaddr_in client_address;
    serveClient(server_socket_fd, client_address);

    close(server_socket_fd);
}

void serveClient(int& server_socket_fd, sockaddr_in& client_address) {
    char buffer[BUFFER_SIZE];
    socklen_t client_len = sizeof(client_address);
    int size;

    recvfrom(server_socket_fd, buffer, sizeof(int), 0, (sockaddr*)&client_address, &client_len);
    memcpy(&size, buffer, sizeof(int));

    vector<int> dur(size);
    recvfrom(server_socket_fd, buffer, size * sizeof(int), 0, (sockaddr*)&client_address, &client_len);
    memcpy(dur.data(), buffer, size * sizeof(int));

    cout << "Server received array: ";
    for (int Duration : dur) {
        cout << Duration << " ";
    }
    cout << endl;

    int sum = 0;
    for (int Duration : dur) {
        sum += Duration;
    }

    memcpy(buffer, &sum, sizeof(int));
    sendto(server_socket_fd, buffer, sizeof(int), 0, (sockaddr*)&client_address, client_len);

    cout << "Server calculated sum: " << sum << endl;
}

void client(string server_ip, int port) {
    int client_socket_fd = 0;
    if ((client_socket_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    if (inet_pton(AF_INET, server_ip.c_str(), &server_address.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        exit(EXIT_FAILURE);
    }

    sendSurgeryData(client_socket_fd, server_address);

    close(client_socket_fd);
}

void sendSurgeryData(int& client_socket_fd, sockaddr_in& server_address) {
    char buffer[BUFFER_SIZE];

    vector<Surgery> surgeries {
            Surgery("S001", 3),
            Surgery("S002", 10),
            Surgery("S003", 5),
            Surgery("S004", 12),
            Surgery("S005", 6)
        };

    int size = surgeries.size();
    vector<int> dur(size);
    for (int i = 0; i < size; ++i) {
        dur[i] = surgeries[i].getDuration();
    }

    cout << "Client sending array: ";
    for (int Duration : dur) {
        cout << Duration << " ";
    }
    cout << endl;

    memcpy(buffer, &size, sizeof(int));
    sendto(client_socket_fd, buffer, sizeof(int), 0, (sockaddr*)&server_address, sizeof(server_address));

    memcpy(buffer, dur.data(), size * sizeof(int));
    sendto(client_socket_fd, buffer, size * sizeof(int), 0, (sockaddr*)&server_address, sizeof(server_address));

    int sum;
    recvfrom(client_socket_fd, buffer, sizeof(int), 0, NULL, NULL);
    memcpy(&sum, buffer, sizeof(int));

    cout << "Client received sum from server: " << sum << endl;
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        cout << "usage:\n\t./SurgeryApp server 8080" << endl;
        cout << "\t./SurgeryApp client 127.0.0.1 8080" << endl;
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "server") == 0) {
        if (argc != 3) {
            cout << "usage:\n\t./SurgeryApp server <port>" << endl;
            return EXIT_FAILURE;
        }

        cout << "Server listening on port " << argv[2] << endl;
        server(atoi(argv[2]));
    }

    if (strcmp(argv[1], "client") == 0) {
        if (argc != 4) {
            cout << "usage:\n\t./SurgeryApp client <server_ip> <port>" << endl;
            return EXIT_FAILURE;
        }
        cout << "Client connecting to server at " << argv[2] << ":" << argv[3] << endl;
        client(argv[2], atoi(argv[3]));
    }

    return EXIT_SUCCESS;
}
