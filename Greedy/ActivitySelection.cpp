#include <iostream>
#include<vector>

using namespace std;

struct Activity{
    int start;
    int finish;

}

bool compare(Activity &a, Activity &b){
    return a.finish<b.finish;
}
void ActivityScheduler(vector<int>a, vector<int>b){
    Activity act;
    for (int i=0;i<=a.size();i++){
        act[i].start =a[i];
        act[i].finish = b[i];
    }
    sort(act.start(),act.end(),compare);
    lastEle = act[0].finish;
    for(int i=1;i<a.size();i++){
        if(act[i].start>lastEle){
            cout << "The start is" << act[i].start <<"The end is"<< act[i].end <<endl;
            lastEle = act[i].finish;
        }
    }
}