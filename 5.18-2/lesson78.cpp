//#include <iostream>
//
//using namespace std;
//
//long long _max = 1e9;
//
//int main()
//{
//    int n;cin >> n;
//    for(int i = n;i < _max;i++)
//    {
//        if(i % 3 == 0)
//        {
//            cout << i << endl;
//            break;
//        }
//    }
//    return 0;
//}

//#include <iostream>
//#include <cstring>
//using namespace std;
//
//const int N = 1e6;
//
//int n;
//string s1,s2;
//int st[N];
//
//int main()
//{
//	cin >> n >> s1 >> s2;
//	
//	
//	if(s1 == s2) 
//	{
//		cout << "NO" << endl;
//	}
//	else
//	{
//		int sum = 0;
//	    for(int i = 0;i < n;i++)
//	    {
//	    	int ret = s1[i] - s2[i];
//	    	sum += ret;
//	    	st[i] = ret;
//	    }
//	    if(sum == 0) 
//	    {
//	    	int cnt = 0;
//	    	int tmp = 0;
//	    	for(int i = 0;i < n;i++)
//	    	{
//	    		if(st[i]) 
//	    		{
//	    			tmp += st[i];
//	    			cnt++;
//				}
//			}
//			if(cnt == 2 && tmp == 0) cout << "YES" << endl;
//			else cout << "NO" << endl;
//		}
//	    else cout << "NO" << endl;
//	}
//	return 0;
//}


//#include <iostream>
//
//using namespace std;
//
//typedef long long LL;
//
//int main()
//{
//	LL n,m;
//	cin >> n >> m;
//	
//	LL cnt1 = 0,cnt2 = 0;
//	
//	cnt1 = m / 5;
//	if(cnt1 <= n)
//	{
//		cnt2 = m % 5;
//	} 
//	else
//	{
//		cnt1 = n;
//		cnt2 = m - n;
//	}
//	
//	cout << cnt1 << " " << cnt2 << endl;
//	
//	
//	return 0;
//} 














































