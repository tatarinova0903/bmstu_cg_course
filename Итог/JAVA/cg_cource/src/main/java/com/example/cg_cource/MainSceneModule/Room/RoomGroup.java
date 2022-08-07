package com.example.cg_cource.MainSceneModule.Room;

import com.example.cg_cource.Helpers.Material;
import com.example.cg_cource.Helpers.MaterialType;
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

    public void rotateByX(int ang) {
        r = new Rotate(ang, Rotate.X_AXIS);
        t = t.createConcatenation(r);
        this.getTransforms().clear();
        this.getTransforms().addAll(t);
    }

    public void rotateByY(int ang) {
        r = new Rotate(ang, Rotate.Y_AXIS);
        t = t.createConcatenation(r);
        this.getTransforms().clear();
        this.getTransforms().addAll(t);
    }

    private Wall prepareBox() {
        return new Wall(100, 20, 50, new Material(MaterialType.PLASTIC));
    }
}