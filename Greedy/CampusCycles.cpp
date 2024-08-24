#include <iostream>
#include <vector>
using namespace std;

vector<int> allocateCycles(vector<vector<int>> &students, vector<vector<int>> &cycles)
{
    int N = students.size(); // Number of students
    int M = cycles.size();   // Number of cycles

    // Vector to store the final assigned cycle index for each student
    vector<int> assignedCycles(N, -1);
    // Vector to keep track of whether a cycle has been used
    vector<bool> cycleUsed(M, false);

    // List to store all possible (student, cycle) pairs with their distances
    vector<tuple<int, int, int>> distances; // (distance, studentIndex, cycleIndex)

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int dist = abs(students[i][0] - cycles[j][0]) + abs(students[i][1] - cycles[j][1]);
            distances.push_back({dist, i, j});
        }
    }

    // Sort the list of distances
    // Sort by distance first, then by student index, and finally by cycle index
    sort(distances.begin(), distances.end());

    for (auto &[dist, studentIndex, cycleIndex] : distances)
    {
        if (assignedCycles[studentIndex] == -1 && !cycleUsed[cycleIndex])
        {
            assignedCycles[studentIndex] = cycleIndex;
            cycleUsed[cycleIndex] = true;
        }
    }

    return assignedCycles;
}

// Example usage
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> students(N, vector<int>(2));
        vector<vector<int>> cycles(M, vector<int>(2));

        for (int i = 0; i < N; i++)
        {
            cin >> students[i][0] >> students[i][1];
        }

        for (int i = 0; i < M; i++)
        {
            cin >> cycles[i][0] >> cycles[i][1];
        }

        vector<int> result = allocateCycles(students, cycles);
        for (int cycleIndex : result)
        {
            cout << cycleIndex << " ";
        }
        cout << endl;
    }

    return 0;
}
