package com.example.cg_cource.MainSceneModule;

import com.example.cg_cource.Material;
import com.example.cg_cource.MaterialType;
import com.example.cg_cource.Wall;
import javafx.scene.*;
import javafx.scene.transform.Rotate;
import javafx.scene.transform.Transform;


public class MainGroup extends Group {
    Rotate r;
    Transform t = new Rotate();

    public MainGroup() {
        Wall wall = prepareBox();
        getChildren().add(wall);
    }

    void rotateByX(int ang) {
        r = new Rotate(ang, Rotate.X_AXIS);
        t = t.createConcatenation(r);
        this.getTransforms().clear();
        this.getTransforms().addAll(t);
    }

    void rotateByY(int ang) {
        r = new Rotate(ang, Rotate.Y_AXIS);
        t = t.createConcatenation(r);
        this.getTransforms().clear();
        this.getTransforms().addAll(t);
    }

    private Wall prepareBox() {
        return new Wall(100, 20, 50, new Material(MaterialType.PLASTIC));
    }
}