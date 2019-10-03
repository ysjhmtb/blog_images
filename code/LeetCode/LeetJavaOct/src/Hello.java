public class Hello {
    public static void main(String[] args) {
        System.out.println("Hello ");
        int[] nums = {2, 7, 11, 15};
        int target = 9;
        TwoSum ref = new TwoSum();
        int[] res = ref.twoSum(nums, target);
        for (int i = 0; i < res.length; i++) {
            System.out.print(res[i] + " ");
        }
    }
}
