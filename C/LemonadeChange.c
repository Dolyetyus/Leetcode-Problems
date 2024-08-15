bool lemonadeChange(int* bills, int billsSize) {
    int banknotes[2] = {0};

    for (int i = 0; i<billsSize; i++){
        if (bills[i]==5){
            banknotes[0]++;
        }
        else if (bills[i]==10){
            if (banknotes[0]==0) return false;
            banknotes[1]++;
            banknotes[0]--;
        }
        else if (bills[i]==20){
            if (banknotes[0]==0) return false;
            if (banknotes[1]==0 && banknotes[0]<3) return false;

            if (banknotes[1]>0){
                banknotes[1]--;
                banknotes[0]--;
            }
            else{
                banknotes[0] = banknotes[0]-3;
            }
        }
    }

    return true;
}
