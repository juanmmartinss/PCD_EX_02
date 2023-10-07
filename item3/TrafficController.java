import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class TrafficController {
    final Lock trava = new ReentrantLock();
    final Condition red_car = trava.newCondition();
    final Condition blue_car = trava.newCondition();

    int libera = 0;	// variável de controle
    int leftQ = 0;
    int rightQ = 0;

    public void enter(String car) {
        if(car.compareTo("red_car")==0) leftQ++;
        if(car.compareTo("blue_car")==0) rightQ++;
        System.out.printf("LQ: %d | RQ: %d\n", leftQ, rightQ);
        trava.lock();
        try{
            if ((libera!=0)&&(car.compareTo("red_car")==0)&&(rightQ > 0)) red_car.await();
            if ((libera!=1)&&(car.compareTo("blue_car")==0)&&(leftQ > 0)) blue_car.await();
                
        } catch (InterruptedException ie) { System.err.println( ie.toString()); }
   }

    public void leave(String car) {
        if (car.compareTo("red_car") == 0){
            leftQ--;
            if(rightQ > 0) {
                libera = (libera + 1) % 2;
                blue_car.signal();
            }
            else red_car.signal();
        }
        if (car.compareTo("blue_car") == 0){
            rightQ--;
            if(leftQ > 0) {
                libera = (libera + 1) % 2;
                red_car.signal();
            }
            else blue_car.signal();
        }
        trava.unlock();
        System.out.printf("LQ: %d | RQ: %d\n", leftQ, rightQ);
    }

}