#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Activity
{
	int start_time;
	int end_time;
	bool operator<(const Activity& other) const
	{
		return end_time < other.end_time;
	}
};

int main()
{

	vector<int> m_activities;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int max_activities = 1; //keeps track of the number of activities that the busy man will be able to do
		vector<Activity> activities;

		int n;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			int start;
			int end;
			cin >> start >> end;
			Activity activity;
			activity.start_time = start;
			activity.end_time = end;
			activities.push_back(activity);
		}

		//Sort the activities based on end time
		sort(activities.begin(), activities.end());

		Activity selected_activity;
		selected_activity = activities[0]; //Select the first activity
		for (int i = 1; i < activities.size(); i++)
		{
			if (activities[i].start_time >= selected_activity.end_time)
			{
				max_activities = max_activities + 1;
				selected_activity = activities[i];
			}
		}
		m_activities.push_back(max_activities);
	}

	for (int i = 0; i < m_activities.size(); i++)
	{
		cout << m_activities[i] << endl;
	}
	
	return 0;
}