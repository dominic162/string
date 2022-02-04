/*https://cybergeeksquad.co/2021/06/split-string-into-unique-primes-solution-amazon-oa.html*/
#include<iostream>
#include<string>
using namespace std;

//fill prime array
void fill(vector<bool> &prime){

	for(int i = 2 ; i <= 31 ; ++i){

		if(prime[i] == true){
			for(int j = i*i ; j <= 1000 ; j += i){
				prime[j] = false;
			}
		}

	}

	retrun ;
}

int main(){

	vector<bool> prime(1001 , true);

	fill(prime);

	string str;
	cin>>str;

	vector<int> dp(str.size() + 1 , 0);
	dp[str.size()] = 1;

	for(int i = str.size() - 1 ; i >= 0 ; i--){

		int crr = 0;

		//inner loop will go only till 3 more places than i as range is less than 1000
		for(int j = i ; j < str.size() ; ++j){
			int r = (str[j] - '0');
			crr = crr*10 + r;
			if(crr == 0 || crr > 1000){
				break;
			} 

			if(crr == 1){
				continue;
			}

			if(prime[crr] == true){
				dp[i] += dp[j + 1];
			}

		}

	}

	cout<<dp[0];

	return 0;
}