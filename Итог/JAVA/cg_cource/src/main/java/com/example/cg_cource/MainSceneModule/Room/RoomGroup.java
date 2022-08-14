package com.example.cg_cource.MainSceneModule.Room;

import com.example.cg_cource.Helpers.*;
import com.example.cg_cource.Objects.SmartBox;
import javafx.geometry.Point3D;
import javafx.scene.Group;
import javafx.scene.transform.Rotate;
import javafx.scene.transform.Transform;

public class RoomGroup extends Group {
    Rotate r;
    Transform t = new Rotate();

    public RoomGroup() {
        SmartBox floor = prepareFloor();
        floor.setTranslateY(Constants.Room.SIZE / 2);
        getChildren().add(floor);

        SmartBox backWall = prepareWall(WallPosition.BACK);
        getChildren().add(backWall);

        SmartBox leftWall = prepareWall(WallPosition.LEFT);
        getChildren().add(leftWall);

        SmartBox rightWall = prepareWall(WallPosition.RIGHT);
        getChildren().add(rightWall);
    }

    public void handleEventFromMenu(MenuEvent menuEvent) {
        switch (menuEvent) {
            case MINUS -> translateZProperty().set(
                    getTranslateZ() + Constants.Zoom.COORD_CHANGE
            );
            case PLUS -> translateZProperty().set(
                    getTranslateZ() - Constants.Zoom.COORD_CHANGE
            );
            case ROTATE_UP -> rotateByX(-10);
            case ROTATE_DOWN -> rotateByX(10);
            case ROTATE_LEFT -> rotateByY(10);
            case ROTATE_RIGHT -> rotateByY(-10);
        }
    }

    private void rotateByX(int ang) {
        r = new Rotate(ang, Rotate.X_AXIS);
        t = t.createConcatenation(r);
        this.getTransforms().clear();
        this.getTransforms().addAll(t);
    }

    private void rotateByY(int ang) {
        r = new Rotate(ang, Rotate.Y_AXIS);
        t = t.createConcatenation(r);
        this.getTransforms().clear();
        this.getTransforms().addAll(t);
    }

    private SmartBox prepareFloor() {
        return new SmartBox(Constants.Room.SIZE, 5, Constants.Room.SIZE, new Material(MaterialType.WOOD));
    }

    private SmartBox prepareWall(WallPosition position) {
        SmartBox res = null;
        switch (position) {
            case BACK -> {
                res = new SmartBox(Constants.Room.SIZE, 5, Constants.Room.SIZE, new Material(MaterialType.PAPER));
                res.translateForBack();
            }
            case LEFT -> {
                res = new SmartBox(Constants.Room.SIZE, 10, Constants.Room.SIZE, new Material(MaterialType.PAPER));
                res.translateForLeft();
            }
            case RIGHT -> {
                res = new SmartBox(Constants.Room.SIZE, 20, Constants.Room.SIZE, new Material(MaterialType.PAPER));
                res.translateForRight();
            }
        }
        return res;
    }
}

