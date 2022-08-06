package com.example.cg_cource;

import javafx.scene.*;

import javafx.scene.image.Image;
import javafx.scene.paint.Color;
import javafx.scene.paint.PhongMaterial;
import javafx.scene.shape.Box;
import javafx.scene.shape.Sphere;
import javafx.scene.transform.Rotate;
import javafx.scene.transform.Transform;

public class MainGroup extends Group {
    Rotate r;
    Transform t = new Rotate();

    public MainGroup() {
        Box box = prepareBox();
        getChildren().add(box);
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

    private Box prepareBox() {
        PhongMaterial material = new PhongMaterial();
//        material.setDiffuseMap(new Image(getClass().getResourceAsStream("..../resources/images/wood.jpg")));
        Box box = new Box(100, 20, 50);
        box.setMaterial(material);
        return box;
    }
}