Maximize the valid value	if (solve(mid)) low = mid + 1;	Store mid in ans	return ans;
Minimize the valid value	if (solve(mid)) high = mid - 1;	Store mid in ans	return ans;
this is the trick based on question
