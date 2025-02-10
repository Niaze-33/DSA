#include<bits/stdc++.h>
#define ll long long
#define mx max_element
#define mn min_element
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define lb lower_bound
#define ub upper_bound
 
using namespace std;

int main()
{
    string s1,s2;
    cin>>s2;
    int n=s2.size();
    s1=s2;
    reverse(s2.begin(),s2.end());
    int c[n+1][n+1];
    char b[n+1][n+1];
    //Initialize the first row and first collum
    for(int i=0;i<=n;i++){
        c[i][0]=0;
        c[0][i]=0;
    }
    //Built the LCS table 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='1';//For top-left diagnal
            }
            else if(c[i][j-1]>c[i-1][j]){
               c[i][j]=c[i][j-1];
               b[i][j]='2';// For left
            }
            else{
                c[i][j]=c[i-1][j];
                b[i][j]='3';//For Right
            }
        }
    }
    //Backtrack for print the LCS
    int i=n,j=n;
    string lps="";
    while(i>0&&j>0){
        if(b[i][j]=='1'){
            //Match found ,add the char to the resulted lcs and move diagnally
            lps+=s1[i-1];
            i--;
            j--;
        }
        else if(b[i][j]=='2'){
            //Move left
            j--;
        }
        else{
            // Move up
            i--;
        }
    }
    reverse(lps.begin(),lps.end());
    cout<<lps.size()<<endl;
    cout<<lps<<endl;
    return 0;
}
