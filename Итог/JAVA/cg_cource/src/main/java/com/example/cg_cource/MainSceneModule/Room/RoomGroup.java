package com.example.cg_cource.MainSceneModule.Room;

import com.example.cg_cource.Helpers.Material;
import com.example.cg_cource.Helpers.MaterialType;
import com.example.cg_cource.Helpers.MenuEvent;
import com.example.cg_cource.Helpers.ScreenConstants;
import com.example.cg_cource.Objects.Wall;
import javafx.scene.Group;
import javafx.scene.transform.Rotate;
import javafx.scene.transform.Transform;

public class RoomGroup extends Group {
    Rotate r;
    Transform t = new Rotate();

    public RoomGroup() {
        Wall wall = prepareBox();
        getChildren().add(wall);
    }

    public void handleEventFromMenu(MenuEvent menuEvent) {
        switch (menuEvent) {
            case MINUS -> translateZProperty().set(
                    getTranslateZ() + ScreenConstants.Zoom.COORD_CHANGE
            );
            case PLUS -> translateZProperty().set(
                    getTranslateZ() - ScreenConstants.Zoom.COORD_CHANGE
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

    private Wall prepareBox() {
        return new Wall(100, 20, 50, new Material(MaterialType.PLASTIC));
    }
}