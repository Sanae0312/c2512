#include <iostream>
#include <vector>
#include <string>

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

int findSum(vector<Surgery>& surgeries) {
	int sum = 0;
	for(int i = 0; i < surgeries.size(); i++) {
		sum = sum + surgeries[i].getDuration();
	}
	return sum;
}

int findMinInFirstHalf(vector<Surgery>& surgeries) {
	int endIndex = surgeries.size()/2;
	
	int minDuration = surgeries[0].getDuration();

	for (int i = 0; i < endIndex; i++) {
		if (surgeries[i].getDuration() < minDuration) {
			minDuration = surgeries[i].getDuration();
        }
    }
	return minDuration;
}

int findMaxInSecondHalf(vector<Surgery>& surgeries) {
	int startIndex = surgeries.size()/2;
    int endIndex = surgeries.size();
	int maxDuration = surgeries[startIndex].getDuration();

	for (int i = startIndex; i < endIndex; i++) {
		if (surgeries[i].getDuration() > maxDuration)
			maxDuration = surgeries[i].getDuration();
    }
	return maxDuration;
}


int main() {
    vector<Surgery> surgeries = {
        Surgery("S001", 3),
        Surgery("S002", 10),
        Surgery("S003", 5),
        Surgery("S004", 12),
        Surgery("S005", 6)
    };
	cout << "Sum of durations is " << findSum(surgeries) << endl;
	cout << "Minimum duration in first half is " << findMinInFirstHalf(surgeries) << endl;
	cout << "Maximum duration in first half is " << findMaxInSecondHalf(surgeries) << endl;
}
