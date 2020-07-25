//lydon分解的duval算法
//lydon串本质是当前串就为最小这个串的最小表示法，所以lydon分解就是将整个串划分为若干个最小表示法的串，并且这种划分具有唯一性。
//lydon分解：将串$s$分解为若干个lydon串$s_1,s_2,\cdots,s_k$，并且满足$s_1>=s_2>=...>=s_k$。
//duval算法核心思想就是通过两个指针来操作，然后根据大小关系来进行指针移位。
//若$k$指针移到$i$，说明找到了一个lydon串，然后开启一个新的循环；否则就说明继续跑循环节或者lydon串已经截止。
vector<string> duval(string const& s) {
  int n = s.size(), i = 0;
  vector<string> factorization;
  while (i < n) {
    int j = i + 1, k = i;
    while (j < n && s[k] <= s[j]) {
      if (s[k] < s[j])
        k = i;
      else
        k++;
      j++;
    }
    while (i <= k) {
      factorization.push_back(s.substr(i, j - k));
      i += j - k;
    }
  }
  return factorization;
}