#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numSubseq(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    long mod[nums.size() + 1];
    mod[0] = 1;
    long to_mod = pow(10, 9) + 7;
    for(int i = 1; i <= nums.size(); i++){
        mod[i] = ((2 * mod[i - 1])) % to_mod; //captures all the mods from 2^0 to 2^n n = num size
    }
    int l = 0;
    int h = nums.size() - 1;
    long ans = mod[nums.size()] - 1;
    while(l <= h){
        if(nums[l] + nums[h] > target){
            ans -= mod[h - l];
            h--;
        }
        else{
            l++;
        }
    }
    long modded = ans % to_mod;
    if(modded < 0){
        return to_mod + modded;
    }
    return modded;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

}
