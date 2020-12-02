def binary_addition(x,y):
        max_len = max(len(x), len(y))
        x = x.zfill(max_len)
        y = y.zfill(max_len)
        result = ''
        carry = 0
        for i in range(max_len-1, -1, -1):
            r = carry
            r += 1 if x[i] == '1' else 0
            r += 1 if y[i] == '1' else 0
            result = ('1' if r % 2 == 1 else '0') + result
            carry = 0 if r < 2 else 1       
        if carry !=0 : result = binary_addition(result,'1')
        return result.zfill(max_len)
    
def onescompliment(a):
    new_data = ''
    for i in range (len(a)):
        if a[i] == '0':
            new_data += "1"
        else:
            new_data +="0"
    return new_data 

def checksumcalculator(x,k):
    blocks = [x[i:i+k] for i in range(0, len(x), k)]
    result = ''.zfill(k)
    for i in range (len(blocks)):
        result = binary_addition(blocks[i],result)
    result = onescompliment(result)  
    return result 

if __name__ == "__main__":
    print("**************** K Srikanth 17ETCS002124 ****************")
    print("")
    while (1):
        print("******** Checksum ********")
        print("Press 1 to compute checksum at the transmitter.")
        print("Press 2 to receive data transmission from transmitter")
        choice = int(input())
        if choice==1:
            print("****** Transmitter Console ******")
            data = input("Enter the 32 bit data to be trasmitted :")
            segmented = int(input("Enter the number for which the data has to be segmented "))
            print ("The Checksum at transmitter is ",checksumcalculator(data,segmented))
        elif choice == 2:
            print("****** Receiver Console ******")
            data = input("Enter recevied data from trasmitter :")
            segmented = int(input("Enter the number for which the data has to be segmented "))
            print ("The Checksum at transmitter is ",checksumcalculator(data,segmented)) 
        elif choice == 3:
            break

 



