package bee;

import world.BeeHive;

/**
 * The male drone bee has a tough life.  His only job is to mate with the queen
 * by entering the queen's chamber and awaiting his royal highness for some
 * sexy time.  Unfortunately his reward from mating with the queen is his
 * endophallus gets ripped off and he perishes soon after mating.
 *
 * @author Sean Strout @ RIT CS
 * @author Daniel Chung
 */
public class Drone extends Bee {
    private boolean mated = false;
    /**
     * When the drone is created they should retrieve the queen's
     * chamber from the bee hive and initially the drone has not mated.
     *
     * @param beeHive the bee hive
     */
    public Drone(BeeHive beeHive){
        super(Role.DRONE, beeHive);
    }

    /**
     * When the drone runs, they check if the bee hive is active.  If so,
     * display a message:<br>
     * <br>
     * <tt>"*D* {bee} enters queen's chamber</tt><br>
     * <br>
     * they perform their sole task of entering the queen's chamber.
     * If they return from the chamber, it can mean only one of two
     * things.  If they mated with the queen, they sleep for the
     * required mating time, and then perish (the beehive should be
     * notified of this tragic event).  You should display a message:<br>
     * <br>
     * <tt>*D* {bee} has perished!</tt><br>
     * <br>
     * <br>
     * Otherwise if the drone has not mated it means they survived the
     * simulation and they should end their run without any
     * sleeping.
     */

    /**
     * Sets the mated state of the current drone.
     */
    public void setMated(){
        this.mated = true;
    }

    /**
     * Does its actual only job which is going into the chamber xd.
     */
    public void run() {
        if (beeHive.isActive()){
            try {
                beeHive.getQueensChamber().enterChamber( this );
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}