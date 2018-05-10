#include <iostream>
#include <vector>

int INVALID_VALUE = INT_MAX;

bool check_bubunwa_impl(std::vector<int> &remain_arr, int K)
{
  if (remain_arr.empty()) return false;
  for (size_t i=0; i<remain_arr.size(); i++) {
	if (remain_arr[i] == INVALID_VALUE) continue;

	if (remain_arr[i] == K) return true;  // find!

	int value = remain_arr[i];

	// check without ith element
	remain_arr[i] = INVALID_VALUE;
	if (check_bubunwa_impl(remain_arr, K)) return true;

	// check using ith element
	if (value < K) {
	  if (check_bubunwa_impl(remain_arr, K-value)) return true;
	}

	// back INVALID_VALUE to original value
	remain_arr[i] = value;
	  
  }

  return false;
}

bool check_bubunwa(const std::vector<int> &arr, int K)
{
  auto copy_arr = arr;
  return check_bubunwa_impl(copy_arr, K);
}

int main()
{
  std::vector<int> arr1{1,2,4,7};
  std::cout << "alg:" << check_bubunwa(arr1, 13) << ", expected: true" << std::endl;

  std::vector<int> arr2{1,2,4,7};
  std::cout << "alg:" << check_bubunwa(arr2, 15) << ", expected: false" << std::endl;
  
 
  return 0;
}
