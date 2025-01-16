#include <iostream>
#include <vector>
#include <string>
#include <thread>

using namespace std;

class Surgery {
	private:
		string surgeryId;
		int Duration;

	public:
		Surgery(string surgeryId, int Duration) : surgeryId(surgeryId), Duration(Duration) {}
		//string GetSurgeryID();
        int getDuration()
        {
	        return Duration;
        }
};

void findSum(vector<Surgery>& surgeries, int& totalDuration) {
		int sum = 0;
	for(int i = 0; i < surgeries.size(); i++) {
		sum = sum + surgeries[i].getDuration();
	}
	  totalDuration = sum;
}

void findMinInFirstHalf(vector<Surgery>& surgeries, int& minDur) {
	int endIndex = surgeries.size()/2;
	
	int minDuration = surgeries[0].getDuration();

	for (int i = 0; i < endIndex; i++) {
		if (surgeries[i].getDuration() < minDuration)
			minDuration = surgeries[i].getDuration();
    }
	  minDur = minDuration;
}

void findMaxInSecondHalf(vector<Surgery>& surgeries, int& maxDur) {
	int startIndex = surgeries.size()/2;
    int endIndex = surgeries.size();
	int maxDuration = surgeries[startIndex].getDuration();

	for (int i = startIndex; i < endIndex; i++) {
		if (surgeries[i].getDuration() > maxDuration)
			maxDuration = surgeries[i].getDuration();
    }
	  maxDur = maxDuration;
}


int main() {
    int totalDuration;
	int minDur;
	int maxDur;
    vector<Surgery> surgeries = {
        Surgery("S001", 3),
        Surgery("S002", 10),
        Surgery("S003", 5),
        Surgery("S004", 12),
        Surgery("S005", 6)
    };

    thread threadsum(findSum, ref(surgeries), ref(totalDuration));
    thread threadfindMinInFirstHalf(findMinInFirstHalf, ref(surgeries), ref(minDur));
    thread threadfindMaxInSecondHalf(findMaxInSecondHalf, ref(surgeries), ref(maxDur));

    threadsum.join();
    threadfindMinInFirstHalf.join();
    threadfindMaxInSecondHalf.join();

	cout << "Sum of durations is " << totalDuration << endl;
	cout << "Minimum duration in first half is " << minDur << endl;
	cout << "Maximum duration in first half is " << maxDur << endl;
}
