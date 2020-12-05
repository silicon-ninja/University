# K Srikanth 17ETCS002124
def binary_addition(x,y): # Perform Binary Addition with x,y
        max_len = max(len(x), len(y)) # length of x,y
        x = x.zfill(max_len)  #fill x with zeros for max length
        y = y.zfill(max_len) #fill y with zeros for max length
        result = '' #initialize result 
        carry = 0 # initialize carray 
        for i in range(max_len-1, -1, -1): # for i in range of the length of a and b
            r = carry # reminder = carry 
            r += 1 if x[i] == '1' else 0 #if x[i] is 1 then reminder = reminder + 1 else 0
            r += 1 if y[i] == '1' else 0 #if y[i] is 1 then reminder = reminder + 1 else 0
            result = ('1' if r % 2 == 1 else '0') + result # Result = if remindner is 1 then 1 else 0 + result 
            carry = 0 if r < 2 else 1   # if reminder < 2 carry = 0 else 1 and exit the loop
        if carry !=0 : result = binary_addition(result,'1') # if carrt is != 0 then result = binary_addition (result,1)
        return result.zfill(max_len) # return result 
    
# K Srikanth 17ETCS002124    
def onescompliment(a): # Perform one's compliment with a
    new_data = '' # initialize new_data
    for i in range (len(a)): # for i in range of a
        if a[i] == '0': # if a[i] = 0 then new_data = new_data + 1 else new_data = new_data + 0
            new_data += "1"
        else:
            new_data +="0"
    return new_data # return new_data 

# K Srikanth 17ETCS002124  
def checksumcalculator(x,k): # Perform checksum of x,k
    blocks = [x[i:i+k] for i in range(0, len(x), k)] # split x with k for i in range of 0, length(x), k
    result = ''.zfill(k) # fill result with for length of k
    for i in range (len(blocks)): # for i in range of length of blocks
        result = binary_addition(blocks[i],result) # Binary Addition of (blocks[i],result)
    result = onescompliment(result)  # Compliment the result onescompliment(result
    return result # return result


# K Srikanth 17ETCS002124  
if __name__ == "__main__": # Main function
    print("**************** K Srikanth 17ETCS002124 ****************") 
    print("")
    while (1): #while loop begins for the menu
        print("******** Checksum ********")
        print("Press 1 to compute checksum at the transmitter.")
        print("Press 2 to receive data transmission from transmitter")
        choice = int(input()) # Choice of input from the menu
        if choice==1: # if choice is 1 then Tramisit the given data
            print("****** Transmitter Console ******")
            data = input("Enter the 32 bit data to be trasmitted :") # enter the 32bit long data 
            # enter the number that data has to be segmented wrt 2^n 
            segmented = int(input("Enter the number for which the data has to be segmented ")) 
            # checksum function with data and segmented as args
            print ("The Checksum at transmitter is ",checksumcalculator(data,segmented)) 
        elif choice == 2: # if choice is 2 then recevie the given data 
            print("****** Receiver Console ******")
            data = input("Enter recevied data from trasmitter :") # enter the 32bit long data with checksum 
            # enter the number that data has to be segmented wrt 2^n
            segmented = int(input("Enter the number for which the data has to be segmented "))
              # checksum function with data and segmented as args
            print ("The Checksum at transmitter is ",checksumcalculator(data,segmented)) 
        elif choice == 3: # if choice is 3 then exit the loop and break
            break 

 



