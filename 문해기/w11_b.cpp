//
// Created by 김석찬 on 2024/12/19.
//

#include<iostream>
#include<queue>

using namespace std;
#define ll long long


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;

    int N, K;
    ll sum;

    while (T--) {
        sum = 0;
        cin >> N >> K;

        ll* time = new ll[N];
        ll* value = new ll[N];
        for (int i = 0; i < N; i++) {
            cin >> time[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> value[i];
        }

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq_time;
        for (int i = 0; i < N; i++) {
            pq_time.push(pair<ll, ll>{time[i], value[i]});
        }
        priority_queue<pair<ll, ll>>pq_value;


        while (!pq_time.empty() || !pq_value.empty()) {
            while (!pq_time.empty() && pq_time.top().first <= K) {
                pq_value.push(pair<ll, ll>{pq_time.top().second, pq_time.top().first});
                pq_time.pop();
            }
            if (!pq_value.empty()) {
                sum = sum + (pq_value.top().first * (K - pq_value.top().second));
                pq_value.pop();
            }
            K++;
        }
        cout << sum << "\n";
    }
}