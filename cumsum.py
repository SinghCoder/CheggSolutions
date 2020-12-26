"""
    The function takes input a list named num_list which is a list of floating numbers
    And it returns a list cumulative_sum_list which stores cumulative sum of elements
    i.e. cumulative_sum[i] stores num_list[0] + num_list[1] + ... + num_list[i]
"""
def calculate_cumulative_sum(num_list):
    # Declare cumulative_sum_list variable to be as a list
    cumulative_sum_list = []
    
    # Check if given input list is empty(length = 0), then return an empty list as output
    if len(num_list) == 0:
        return cumulative_sum_list

    # Number of elements in cumulative_sum_list should be same as num_list, so enter those many elements in cumulative_sum_list
    # If num_list's size is n, add n 0s in cumulative_sum_list
    for i in range(len(num_list)):
        cumulative_sum_list.append(0.0)

    # First element of cumulative_sum_list will be same as first element of num_list
    # Since that will signify the sum of elements 0..0 i.e. only first element
    cumulative_sum_list[0] = num_list[0]

    # Now traverse in a loop and since cumulative_sum_list[i] = num_list[0] + num_list[1] + ... num_list[i-1] + num+list[i]
    # It can be written as cumulative_sum_list[i] = (num_list[0] + num_list[1] + ... num_list[i-1] ) + num+list[i] = cumulative_sum_list[i-1] + num_list[i]
    # i.e. cumulative_sum_list[i] = cumulative_sum_list[i-1] + num_list[i]

    for i in range(1, len(num_list)):
        cumulative_sum_list[i] = cumulative_sum_list[i-1] + num_list[i]
    
    # Return the output
    return cumulative_sum_list

# Checking the correctness of above using a testcase
if __name__ == "__main__":
    num_list = [1.5, 2.4, 6.5]
    cumulative_sum_list = calculate_cumulative_sum(num_list)
    print("Num LIST : ", num_list)
    print("Cumulative Sum List: ", cumulative_sum_list)