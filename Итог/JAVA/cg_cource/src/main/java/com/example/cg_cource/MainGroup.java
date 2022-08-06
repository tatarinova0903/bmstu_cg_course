package com.example.cg_cource;

import javafx.scene.*;

import javafx.scene.shape.Sphere;

public class MainGroup extends Group {

    public MainGroup() {
        Sphere sphere = new Sphere(50);
        getChildren().add(sphere);
    }
}