#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool reachDestination(int sx, int sy, int dx, int dy) {
    // Write your code here
    if(sx==dx && sy==dy) return true;
    if(dx<sx || dy <sy) return false;
    if(dx<dy)
    {
        return reachDestination(sx, sy, dx, dy-dx);
    }
    else {
        return reachDestination(sx, sy, dx-dy, dy);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a,b,c,d;
        cin >> a>> b>> c>> d;

        
        if(reachDestination(a,b,c,d)){
            cout<< "true" << endl;
        }
        else{
            cout << "false" << endl;
        }
    }
}