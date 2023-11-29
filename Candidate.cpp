#include "Candidate.h"
using namespace std;

Candidate::Candidate() {
	CandidateID = -1;
	FName = "";
	LName ="";
	TotalVotes = 0;
	BallotList = BallotLinkedList();
	//DistrictIDs = {0};
	//^ fills in the values of candidate with blank or null values
};

Candidate::~Candidate() {
};

Candidate::Candidate(Candidate& candidate) {
	CandidateID = candidate.GetCandidateID();
	FName = candidate.GetFName();
	LName = candidate.GetLName();
	TotalVotes = candidate.GetTotalVotes();
	BallotList = candidate.GetBallotList();
	//DistrictIDs = { 0 };
	//^ copies the values currently stored in the candidate class
};

Candidate::Candidate(string first, string last, double ID) {
	CandidateID = ID;
	FName = first;
	LName = last;
	TotalVotes = 0;
	BallotList = BallotLinkedList();
	//DistrictIDs = { 0 };
	//^ allows manual input of values for Candidate (not manually input through keyboard, instead values are passed when the constructor is called.
	// see Tabulation.cpp for an example.)
};

double Candidate::GetCandidateID() {
	return CandidateID;
	//^ returns the value currently stored in CandidateID
};

double Candidate::GetTotalVotes() {
	return TotalVotes;
	//^ returns the value currently stored in TotalVotes
};

string Candidate::GetFName() {
	return FName;
	//^ returns the value currently stored in FName
};

string Candidate::GetLName() {
	return LName;
	//^ returns the value currently stored in LName
};

bool Candidate::IDsEqual(Candidate candidate)
{
	return (candidate.GetCandidateID() == CandidateID);
	//^ returns true or false depending on whether the current value in CandidateID is the same
};

void Candidate::Print() {
	cout << "----------------" << endl;
	cout << "Candidate " << CandidateID << ": " << std::endl;
	cout << "First Name: " << FName << std::endl;
	cout << "Last Name: " << LName << std::endl;
	cout << "Total Votes: " << TotalVotes << std::endl;
	cout << "This Candidate is a part of these districts: ";
	/*if (DistrictIDs.size() != 0)
	{
		for (int i = 0; i < DistrictIDs.size(); i++)
		{
			cout << DistrictIDs[i] << ", ";
		}
	}*/
	cout << endl;
	cout << "This candidate holds these ballots: " << endl;
	BallotLinkedList list = BallotList.Copy();

	while (!list.Empty()) {

		list.ReturnFrontItem().Print();

		list.RemoveFront();

	}

	cout << "----------------" << endl;
	//^ displays the Candidate's ID, first name, and last name in order
	//perhaps add statements to display other information, like district
};



void Candidate::CountVotes() {
	double i = 0; //creates a local variable to keep track of the total votes counted in this method
	BallotLinkedList list = BallotList.Copy(); //copies the list of ballots so the original being used isn't changed, and stores it in a local variable
	while(!list.Empty()) { //loops through the copied list one at a time until its empty
		list.RemoveFront(); //removes the front item in the list, this is why we didn't just edit the original list.
		i++; //increments our local total by 1
	}
	TotalVotes = i; //sets the value of TotalVotes to the value stored in our local variable, which should be accurate to the total number of votes
	
};

void Candidate::AddBallot(Ballot &ballot) 
{
	//ballot.Print();
	BallotList.AddItemToFront(ballot);
	//^ adds a new ballot to the front of the list, using the values stored in the ballot parameter passed to the method
};

void Candidate::RemoveBallot(Ballot &ballot) {
	BallotList.RemoveItem(ballot);
	//^ removes the ballot stored in the list if its values correlate to the values passed in the ballot parameter
	//may want to include an exception/catch algorithm that will display an error when the ballot passed does not exist in the list
};

BallotLinkedList Candidate::GetBallotList() {
	return BallotList;
	//^ returns the list of ballots

}
