#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;

//finds the optimal combinations of coins that sum to S with DP
int optimal_solution(vector<int> & memo, const vector<int> & coins, int S) {
	//we want to discard invalid solutions
	if (S < 0) {
		return INF;
	}
	//no need to compute
	if (memo[S] > -1)
		return memo[S];

	//test all coin combinations
	int min_coins = optimal_solution(memo, coins, S - coins[0]) + 1;
	for (int i = 1; i < coins.size(); ++i) {
		min_coins = min(min_coins, optimal_solution(memo, coins, S - coins[i]) + 1);
	}

	//and save and use the best one
	return memo[S] = min_coins;
}

int greedy_solution(vector<int> & memo, const vector<int> & coins, int S) {
	//no need to compute
	if (memo[S] > -1)
		return memo[S];

	//take the biggest coin
	for (int i = coins.size() - 1; i > -1; --i) {
		if (S >= coins[i]) {
			//and repeat
			return memo[S] = greedy_solution(memo, coins, S - coins[i]) + 1;
		}
	}
}

int main() {
	//put all coins in a simple vector
	int n;
	cin >> n;
	vector<int> coins(n);
	for (int i = 0; i < n; ++i) {
		cin >> coins[i];
	}

	//the smallest counterexample is less than the sum of 
	//the two largest denominations
	vector<int> memo1(coins[n - 1] + coins[n - 2], -1);
	vector<int> memo2(coins[n - 1] + coins[n - 2], -1);

	//necesary base case
	memo1[0] = memo2[0] = 0;

	bool is_con = true;

	//find a (possible) counterexample
	for (int i = 1; i < memo1.size(); ++i) {
		//if the greedy and dp solutions yield dif. results, not cononical
		if (greedy_solution(memo2, coins, i) !=
			optimal_solution(memo1, coins, i)) {
			is_con = false;
			break;
		}
	}

	if (is_con)
		cout << "canonical" << endl;
	else
		cout << "non-canonical" << endl;

	system("pause");
	return 0;
}