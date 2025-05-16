#include <iostream>
#include <string>
using namespace std;

// Forward declaration for Job class
class Job;

// JobExpectation class (Custom Exception class)
class JobExpectation {
private:
    Job job;           // Job object
    string errorMsg;   // Error message

public:
    // Constructor that takes a Job object and an error message
    JobExpectation(Job j, const string& msg) : job(j), errorMsg(msg) {}

    // Getter for the error message
    string getErrorMessage() const {
        return errorMsg;
    }

    // Getter for the Job object
    Job getJob() const {
        return job;
    }
};

// Job class
class Job {
private:
    int Job_ID;
    float fee;

public:
    // Constructor
    Job(int id = 0, float f = 0) : Job_ID(id), fee(f) {}

    // Friend function to overload the extraction (>>) operator
    friend istream& operator>>(istream& in, Job& job);

    // Friend function to overload the insertion (<<) operator
    friend ostream& operator<<(ostream& out, const Job& job);

    // Getter for Job_ID
    int getJobID() const {
        return Job_ID;
    }

    // Getter for fee
    float getFee() const {
        return fee;
    }
};

// Overloading the extraction operator (>>)
istream& operator>>(istream& in, Job& job) {
    cout << "Enter Job ID: ";
    in >> job.Job_ID;

    cout << "Enter Fee for Job: ";
    in >> job.fee;

    // If fee is below $250, throw a JobExpectation exception
    if (job.fee < 250) {
        throw JobExpectation(job, "Fee is too low. Job fee must be $250 or higher.");
    }

    return in;
}

// Overloading the insertion operator (<<)
ostream& operator<<(ostream& out, const Job& job) {
    out << "Job ID: " << job.Job_ID << ", Fee: $" << job.fee;
    return out;
}

int main() {
    const int jobCount = 8;  // Total number of jobs
    Job jobs[jobCount];      // Array to hold the Job objects

    for (int i = 0; i < jobCount; i++) {
        while (true) {
            try {
                cout << "\nEnter details for Job " << i + 1 << ":\n";
                cin >> jobs[i];  // Read job details
                break;  // Break if no exception was thrown
            }
            catch (JobExpectation& ex) {
                // Catch the exception and print the error message
                cout << "Error: " << ex.getErrorMessage() << endl;
                cout << "Please enter a valid job again.\n";
            }
        }
    }

    // Output all jobs entered
    cout << "\nAll Jobs entered:\n";
    for (int i = 0; i < jobCount; i++) {
        cout << jobs[i] << endl;
    }

    return 0;
}
