package com.example.cg_cource;

import javafx.event.ActionEvent;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Alert;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;

class ResizableCanvas extends Canvas {
    private final GraphicsContext gc = getGraphicsContext2D();
    private double oldWidth = getWidth();
    private double oldHeight = getHeight();
    private final MainController controller;

    public ResizableCanvas(MainController controller) {
        this.controller = controller;
//        widthProperty().addListener(evt -> draw());
//        heightProperty().addListener(evt -> draw());
    }

    private void draw() {
        double width = getWidth();
        double height = getHeight();
//        if (width == 0 || height == 0) { return; }
//        double deltaWidth = width / (oldWidth == 0 ? width : oldWidth);
//        double deltaHeight = height / (oldHeight == 0 ? height : oldHeight);
        gc.clearRect(0, 0, width, height);

        gc.setFill(Color.BLACK);
        gc.setLineWidth(0.4);

        oldWidth = width;
        oldHeight = height;
    }

    @Override
    public boolean isResizable() {
        return true;
    }

    @Override
    public double prefWidth(double height) { return getWidth(); }

    @Override
    public double prefHeight(double width) {
        return getHeight();
    }


    static class Constants {
        static double pointDiameter = 6.0;
        static double pointRadius = Constants.pointDiameter / 2;
    }
}
