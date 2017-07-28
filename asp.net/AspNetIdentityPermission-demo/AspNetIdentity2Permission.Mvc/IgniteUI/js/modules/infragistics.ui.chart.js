﻿/*!@license
 * Infragistics.Web.ClientUI Chart 14.2.20142.1018
 *
 * Copyright (c) 2011-2014 Infragistics Inc.
 *
 * http://www.infragistics.com/
 *
 * Depends on:
 * jquery-1.4.4.js
 * jquery.ui.core.js
 * jquery.ui.widget.js
 * infragistics.util.js
 * infragistics.dv.core.js
 * infragistics.chart_piechart.js
 * infragistics.chart_categorychart.js
 * infragistics.chart_financialchart.js
 * infragistics.chart_polarchart.js
 * infragistics.chart_radialchart.js
 * infragistics.chart_rangecategorychart.js
 * infragistics.chart_scatterchart.js
 * infragistics.datasource.js
 * infragistics.dvcommonwidget.js
 */
if(typeof jQuery!=="function"){throw new Error("jQuery is undefined")}(function($){$.widget("ui.igDataChart",{options:{syncChannel:null,synchronizeVertically:true,syncrhonizeHorizontally:false,crosshairPoint:{x:NaN,y:NaN},windowRect:null,horizontalZoomable:false,verticalZoomable:false,windowResponse:null,windowRectMinWidth:0,overviewPlusDetailPaneVisibility:"collapsed",crosshairVisibility:"collapsed",plotAreaBackground:null,defaultInteraction:"dragZoom",dragModifier:"none",panModifier:"shift",previewRect:null,windowPositionHorizontal:0,windowPositionVertical:0,windowScaleHorizontal:1,windowScaleVertical:1,circleMarkerTemplate:null,triangleMarkerTemplate:null,pyramidMarkerTemplate:null,squareMarkerTemplate:null,diamondMarkerTemplate:null,pentagonMarkerTemplate:null,hexagonMarkerTemplate:null,tetragramMarkerTemplate:null,pentagramMarkerTemplate:null,hexagramMarkerTemplate:null,topMargin:0,leftMargin:0,rightMargin:0,bottomMargin:0,autoMarginWidth:20,autoMarginHeight:0,isSquare:false,gridMode:"behindSeries",brushes:null,markerBrushes:null,outlines:null,markerOutlines:null,width:null,height:null,size:null,dataSource:null,dataSourceUrl:null,dataSourceType:null,responseDataKey:null,isSurfaceInteractionDisabled:false,animateSeriesWhenAxisRangeChanges:false,title:null,subtitle:null,titleTextStyle:null,titleTopMargin:0,titleLeftMargin:0,titleRightMargin:0,titleBottomMargin:0,subtitleTextStyle:null,subtitleTopMargin:0,subtitleLeftMargin:0,subtitleRightMargin:0,subtitleBottomMargin:0,titleTextColor:"black",subtitleTextColor:"black",titleHorizontalAlignment:"center",subtitleHorizontalAlignment:"center",highlightingTransitionDuration:300,useTiledZooming:false,preferHigherResolutionTiles:false,zoomTileCacheSize:30,legend:{element:null,type:"legend",width:null,height:null},axes:[{type:null,name:null,dataSource:null,dataSourceUrl:null,dataSourceType:null,responseDataKey:null,remove:false,labelLocation:null,labelVisibility:"visible",labelExtent:null,labelAngle:0,labelTextStyle:null,labelTextColor:null,formatLabel:null,stroke:null,strokeThickness:1,strip:null,majorStroke:null,majorStrokeThickness:1,minorStroke:null,minorStrokeThickness:1,isInverted:false,crossingAxis:null,crossingValue:null,coercionMethods:null,label:null,gap:0,overlap:0,startAngleOffset:0,interval:0,displayType:null,minimumValue:0,maximumValue:0,dateTimeMemberPath:null,referenceValue:0,isLogarithmic:false,logarithmBase:10,radiusExtentScale:.75,innerRadiusExtentScale:0,title:null,titleTextStyle:null,titleMargin:0,titleHorizontalAlignment:"center",titleVerticalAlignment:"center",titlePosition:"auto",titleTopMargin:0,titleLeftMargin:0,titleRightMargin:0,titleBottomMargin:0,labelHorizontalAlignment:"right",labelVerticalAlignment:"top",labelMargin:0,labelTopMargin:0,labelLeftMargin:0,labelRightMargin:0,labelBottomMargin:0,showFirstLabel:true,titleAngle:0,tickLength:0,tickStrokeThickness:.5,tickStroke:"black",useClusteringMode:false}],series:[{type:null,name:null,dataSource:null,dataSourceUrl:null,dataSourceType:null,responseDataKey:null,remove:false,showTooltip:false,tooltipTemplate:null,legend:{element:null,type:"legend",width:null,height:null},legendItemVisibility:"visible",legendItemBadgeTemplate:null,legendItemTemplate:null,discreteLegendItemTemplate:null,transitionDuration:0,transitionEasingFunction:null,resolution:1,title:null,brush:null,outline:null,thickness:0,coercionMethods:null,markerType:"none",markerTemplate:null,markerBrush:null,markerOutline:null,xAxis:null,yAxis:null,xMemberPath:null,yMemberPath:null,trendLineType:"none",trendLineBrush:null,trendLineThickness:1.5,trendLinePeriod:7,trendLineZIndex:1001,maximumMarkers:400,unknownValuePlotting:"dontPlot",radiusMemberPath:null,radiusScale:null,labelMemberPath:null,fillMemberPath:null,fillScale:null,angleAxis:null,valueAxis:null,clipSeriesToBounds:null,valueMemberPath:null,radiusX:2,radiusY:2,angleMemberPath:null,radiusAxis:null,useCartesianInterpolation:true,negativeBrush:null,splineType:"natural",lowMemberPath:null,highMemberPath:null,openMemberPath:null,closeMemberPath:null,volumeMemberPath:null,displayType:"candlestick",ignoreFirst:0,period:0,shortPeriod:0,longPeriod:0,markerCollisionAvoidance:"none",useHighMarkerFidelity:false,useBruteForce:false,progressiveLoad:true,mouseOverEnabled:false,useSquareCutoffStyle:false,heatMinimum:0,heatMaximum:50,heatMinimumColor:"black",heatMaximumColor:"red",series:null,isDropShadowEnabled:false,useSingleShadow:true,shadowColor:"rgba(95,95,95,0.5)",shadowBlur:10,shadowOffsetX:5,shadowOffsetY:5,isTransitionInEnabled:false,transitionInSpeedType:"auto",transitionInMode:"auto",transitionInDuration:500,radius:2,areaFillOpacity:1,expectFunctions:false,useInterpolation:false,skipUnknownValues:false,verticalLineVisibility:"visible",horizontalLineVisibility:"visible",targetSeries:null,targetAxis:null,isCustomCategoryStyleAllowed:false,isCustomCategoryMarkerStyleAllowed:false,isHighlightingEnabled:false,bandHighlightWidth:10,highlightType:"auto",tooltipPosition:"auto",cursorPosition:null,isDefaultCrosshairDisabled:true,useIndex:false,useLegend:false}],theme:"c"},css:{chart:"ui-corner-all ui-widget-content ui-chart-container",unsupportedBrowserClass:"ui-html5-non-html5-supported-message ui-helper-clearfix  ui-html5-non-html5",tooltip:"ui-chart-tooltip ui-widget-content ui-corner-all",seriesPalettes:"ui-chart-palette-n",seriesFillPalettes:"ui-chart-fill-palette-n",seriesOutlinePalettes:"ui-chart-outline-palette-n",areaFillOpacity:"ui-chart-area-fill-opacity",axis:"ui-chart-axis",axisStroke:"ui-chart-axis-stroke",axisMajorStroke:"ui-chart-axis-major-line",alignedGridLines:"ui-chart-aligned-gridlines",categoryAxisTick:"ui-chart-category-axis-tick",horizontalAxisLabels:"ui-horizontal-axis-labels",verticalAxisLabels:"ui-vertical-axis-labels",angularAxisLabels:"ui-angular-axis-labels",radialAxisLabels:"ui-radial-axis-labels",title:"ui-chart-title",subtitle:"ui-chart-subtitle",horizontalAxisTitle:"ui-chart-horizontal-axis-title",verticalAxisTitle:"ui-chart-vertical-axis-title",legendItemsList:"ui-chart-legend-items-list",legendItemsText:"ui-chart-legend-item-text",legendItemsBadge:"ui-chart-legend-item-badge"},events:{tooltipShowing:"tooltipShowing",tooltipShown:"tooltipShown",tooltipHiding:"tooltipHiding",tooltipHidden:"tooltipHidden",browserNotSupported:"browserNotSupported",seriesCursorMouseMove:null,seriesMouseLeftButtonDown:null,seriesMouseLeftButtonUp:null,seriesMouseMove:null,seriesMouseEnter:null,seriesMouseLeave:null,windowRectChanged:null,gridAreaRectChanged:null,refreshCompleted:null,axisRangeChanged:null,typicalBasedOn:null,progressiveLoadStatusChanged:null,assigningCategoryStyle:null,assigningCategoryMarkerStyle:null},_createWidget:function(options,element){this._fixCss();this.dvWidget=new $.ig.dvCommonWidget(this);this.dvWidget._createWidget(options,element,this)},_init:function(){},_create:function(){this._fixCss();this.dvWidget._create()},_fixCss:function(){if(this.css.chart.indexOf("{0}")>-1){this.css.chart=this.css.chart.replace("{0}",this.options.theme);this.css.tooltip=this.css.tooltip.replace("{0}",this.options.theme)}},_setOption:function(key,value){this.dvWidget._setOption(key,value)},option:function(){return this.dvWidget.option.apply(this.dvWidget,arguments)},widget:function(){return this.element},id:function(){return this.element[0].id},exportImage:function(width,height){return this.dvWidget._getImage(width,height,this)},destroy:function(){if(this._chart){this._chart.destroy();this._chart=null}this.dvWidget._destroy(this);$.Widget.prototype.destroy.apply(this,arguments)},styleUpdated:function(){this._chart.styleUpdated();return this},resetZoom:function(){this._chart.resetZoom();return this},addItem:function(item,targetName){var dataSourceId=targetName||this._containerSourceID;if(this.dataSources[dataSourceId]){this.dataSources[dataSourceId].addRow(null,item,true)}},insertItem:function(item,index,targetName){var dataSourceId=targetName||this._containerSourceID;if(this.dataSources[dataSourceId]){this.dataSources[dataSourceId].insertRow(null,item,index,true)}},removeItem:function(index,targetName){var dataSourceId=targetName||this._containerSourceID;if(this.dataSources[dataSourceId]){this.dataSources[dataSourceId].deleteRow(index,true)}},setItem:function(index,item,targetName){var dataSourceId=targetName||this._containerSourceID;if(this.dataSources[dataSourceId]){this.dataSources[dataSourceId].updateRow(index,item,true)}},notifySetItem:function(dataSource,index,newItem,oldItem){this._chart.notifySetItem(dataSource,index,oldItem,newItem);return this},notifyClearItems:function(dataSource){this._chart.notifyClearItems(dataSource);return this},notifyInsertItem:function(dataSource,index,newItem){this._chart.notifyInsertItem(dataSource,index,newItem);return this},notifyRemoveItem:function(dataSource,index,oldItem){this._chart.notifyRemoveItem(dataSource,index,oldItem);return this},scrollIntoView:function(targetName,item){var target=this.dvWidget._getNotifyTarget(targetName);if(target&&target.scrollIntoView){target.scrollIntoView(item)}return this},scaleValue:function(targetName,unscaledValue){var target=this.dvWidget._getNotifyTarget(targetName);if(target&&target.scaleValue){return target.scaleValue(unscaledValue)}return 0},unscaleValue:function(targetName,scaledValue){var target=this.dvWidget._getNotifyTarget(targetName);if(target&&target.unscaleValue){return target.unscaleValue(scaledValue)}return 0},notifyVisualPropertiesChanged:function(targetName){var target=this.dvWidget._getNotifyTarget(targetName);if(target&&target.notifyVisualPropertiesChanged){return target.notifyVisualPropertiesChanged()}return this},flush:function(){this._chart.flush()},exportVisualData:function(){return this._chart.exportVisualData()},getActualMinimumValue:function(targetName){var target=this.dvWidget._getNotifyTarget(targetName);if(target&&target.actualMinimumValue){return target.actualMinimumValue()}return 0},getActualMaximumValue:function(targetName){var target=this.dvWidget._getNotifyTarget(targetName);if(target&&target.actualMaximumValue){return target.actualMaximumValue()}return 0},print:function(){this.dvWidget._print()},renderSeries:function(targetName,animate){var target=this.dvWidget._getNotifyTarget(targetName);if(target&&target.renderSeries){return target.renderSeries(animate)}return this},getItemIndex:function(targetName,worldPoint){var target=this.dvWidget._getNotifyTarget(targetName),p=$.ig.APIFactory.prototype.createPoint(worldPoint.x,worldPoint.y);if(target&&target.getItemIndex){return target.getItemIndex(p)}},getItem:function(targetName,worldPoint){var target=this.dvWidget._getNotifyTarget(targetName),p=$.ig.APIFactory.prototype.createPoint(worldPoint.x,worldPoint.y);if(target&&target.getItem){return target.getItem(p)}},_flattenPoint:function(point){var retPoint={__x:point.__x,__y:point.__y,x:point.__x,y:point.__y};return retPoint},getSeriesValue:function(targetName,worldPoint,useInterpolation,skipUnknowns){var target=this.dvWidget._getNotifyTarget(targetName),p=$.ig.APIFactory.prototype.createPoint(worldPoint.x,worldPoint.y);if(target&&target.getSeriesValue){return target.getSeriesValue(p,useInterpolation,skipUnknowns)}},getSeriesValuePosition:function(targetName,worldPoint,useInterpolation,skipUnknowns){var target=this.dvWidget._getNotifyTarget(targetName),p=$.ig.APIFactory.prototype.createPoint(worldPoint.x,worldPoint.y);if(target&&target.getSeriesValuePosition){return this._flattenPoint(target.getSeriesValuePosition(p,useInterpolation,skipUnknowns))}},getSeriesValuePositionFromSeriesPixel:function(targetName,seriesPoint,useInterpolation,skipUnknowns){var target=this.dvWidget._getNotifyTarget(targetName),p=$.ig.APIFactory.prototype.createPoint(seriesPoint.x,seriesPoint.y);if(target&&target.getSeriesValuePositionFromSeriesPixel){return this._flattenPoint(target.getSeriesValuePositionFromSeriesPixel(p,useInterpolation,skipUnknowns))}},getSeriesValueFromSeriesPixel:function(targetName,seriesPoint,useInterpolation,skipUnknowns){var target=this.dvWidget._getNotifyTarget(targetName),p=$.ig.APIFactory.prototype.createPoint(seriesPoint.x,seriesPoint.y);if(target&&target.getSeriesValueFromSeriesPixel){return target.getSeriesValueFromSeriesPixel(p,useInterpolation,skipUnknowns)}},getSeriesHighValue:function(targetName,worldPoint,useInterpolation,skipUnknowns){var target=this.dvWidget._getNotifyTarget(targetName),p=$.ig.APIFactory.prototype.createPoint(worldPoint.x,worldPoint.y);if(target&&target.getSeriesHighValue){return target.getSeriesHighValue(p,useInterpolation,skipUnknowns)}},getSeriesHighValuePosition:function(targetName,worldPoint,useInterpolation,skipUnknowns){var target=this.dvWidget._getNotifyTarget(targetName),p=$.ig.APIFactory.prototype.createPoint(worldPoint.x,worldPoint.y);if(target&&target.getSeriesHighValuePosition){return this._flattenPoint(target.getSeriesHighValuePosition(p,useInterpolation,skipUnknowns))}},getSeriesHighValuePositionFromSeriesPixel:function(targetName,seriesPoint,useInterpolation,skipUnknowns){var target=this.dvWidget._getNotifyTarget(targetName),p=$.ig.APIFactory.prototype.createPoint(seriesPoint.x,seriesPoint.y);if(target&&target.getSeriesHighValuePositionFromSeriesPixel){return this._flattenPoint(target.getSeriesHighValuePositionFromSeriesPixel(p,useInterpolation,skipUnknowns))}},getSeriesHighValueFromSeriesPixel:function(targetName,seriesPoint,useInterpolation,skipUnknowns){var target=this.dvWidget._getNotifyTarget(targetName),p=$.ig.APIFactory.prototype.createPoint(seriesPoint.x,seriesPoint.y);if(target&&target.getSeriesHighValueFromSeriesPixel){return target.getSeriesHighValueFromSeriesPixel(p,useInterpolation,skipUnknowns)}},getSeriesLowValue:function(targetName,worldPoint,useInterpolation,skipUnknowns){var target=this.dvWidget._getNotifyTarget(targetName),p=$.ig.APIFactory.prototype.createPoint(worldPoint.x,worldPoint.y);if(target&&target.getSeriesLowValue){return target.getSeriesLowValue(p,useInterpolation,skipUnknowns)}},getSeriesLowValuePosition:function(targetName,worldPoint,useInterpolation,skipUnknowns){var target=this.dvWidget._getNotifyTarget(targetName),p=$.ig.APIFactory.prototype.createPoint(worldPoint.x,worldPoint.y);if(target&&target.getSeriesLowValuePosition){return this._flattenPoint(target.getSeriesLowValuePosition(p,useInterpolation,skipUnknowns))}},getSeriesLowValuePositionFromSeriesPixel:function(targetName,seriesPoint,useInterpolation,skipUnknowns){var target=this.dvWidget._getNotifyTarget(targetName),p=$.ig.APIFactory.prototype.createPoint(seriesPoint.x,seriesPoint.y);if(target&&target.getSeriesLowValuePositionFromSeriesPixel){return this._flattenPoint(target.getSeriesLowValuePositionFromSeriesPixel(p,useInterpolation,skipUnknowns))}},getSeriesLowValueFromSeriesPixel:function(targetName,seriesPoint,useInterpolation,skipUnknowns){var target=this.dvWidget._getNotifyTarget(targetName),p=$.ig.APIFactory.prototype.createPoint(seriesPoint.x,seriesPoint.y);if(target&&target.getSeriesLowValueFromSeriesPixel){return target.getSeriesLowValueFromSeriesPixel(p,useInterpolation,skipUnknowns)}},getItemIndexFromSeriesPixel:function(targetName,seriesPoint){var target=this.dvWidget._getNotifyTarget(targetName),p=$.ig.APIFactory.prototype.createPoint(seriesPoint.x,seriesPoint.y);if(target&&target.getItemIndexFromSeriesPixel){return target.getItemIndexFromSeriesPixel(p)}},getItemFromSeriesPixel:function(targetName,seriesPoint){var target=this.dvWidget._getNotifyTarget(targetName),p=$.ig.APIFactory.prototype.createPoint(seriesPoint.x,seriesPoint.y);if(target&&target.getItemFromSeriesPixel){return target.getItemFromSeriesPixel(p)}},getSeriesOffsetValue:function(targetName){var target=this.dvWidget._getNotifyTarget(targetName);if(target&&target.getOffsetValue){return target.getOffsetValue()}},getSeriesCategoryWidth:function(targetName){var target=this.dvWidget._getNotifyTarget(targetName);if(target&&target.getCategoryWidth){return target.getCategoryWidth()}},replayTransitionIn:function(targetName){var target=this.dvWidget._getNotifyTarget(targetName);if(target&&target.replayTransitionIn){target.replayTransitionIn()}return this},simulateHover:function(targetName,seriesPoint){var target=this.dvWidget._getNotifyTarget(targetName);if(target&&target.simulateHover){target.simulateHover($.ig.APIFactory.prototype.createPoint(seriesPoint.x,seriesPoint.y))}return this},moveCursorPoint:function(targetName,worldPoint){var target=this.dvWidget._getNotifyTarget(targetName);if(target&&target.moveCursorPoint){target.moveCursorPoint($.ig.APIFactory.prototype.createPoint(worldPoint.x,worldPoint.y))}return this},startTiledZoomingIfNecessary:function(){this._chart.startTiledZoomingIfNecessary();return this},endTiledZoomingIfRunning:function(){this._chart.endTiledZoomingIfRunning();return this},clearTileZoomCache:function(){this._chart.clearTileZoomCache();return this}});$.extend($.ui.igDataChart,{version:"14.2.20142.1018"});$.widget("ui.igPieChart",{options:{width:null,height:null,dataSource:null,dataSourceUrl:null,dataSourceType:null,responseDataKey:null,valueMemberPath:null,labelMemberPath:null,labelsPosition:"center",leaderLineVisibility:"visible",leaderLineType:"straightLine",leaderLineMargin:6,othersCategoryThreshold:3,formatLabel:null,othersCategoryStyle:null,othersCategoryType:"percent",othersCategoryText:"Others",explodedRadius:.2,radiusFactor:.9,allowSliceSelection:null,allowSliceExplosion:null,explodedSlices:null,showTooltip:false,tooltipTemplate:null,legend:{element:null,type:"item",width:null,height:null},labelExtent:10,startAngle:0,sweepDirection:"clockwise",selectedStyle:null,brushes:null,outlines:null,legendItemTemplate:null,legendItemBadgeTemplate:null,textStyle:null,theme:"c"},css:{chart:"ui-corner-all ui-widget-content ui-chart-piechart-container",unsupportedBrowserClass:"ui-html5-non-html5-supported-message ui-helper-clearfix ui-html5-non-html5",tooltip:"ui-chart-tooltip ui-widget-content ui-corner-all"},events:{tooltipShowing:"tooltipShowing",tooltipShown:"tooltipShown",tooltipHiding:"tooltipHiding",tooltipHidden:"tooltipHidden",browserNotSupported:"browserNotSupported",sliceClick:null},_createWidget:function(options,element){this._fixCss();this.dvWidget=new $.ig.dvCommonWidget(this);this.dvWidget._createWidget(options,element,this)},_create:function(){this._fixCss();this.dvWidget._create()},_fixCss:function(){if(this.css.chart.indexOf("{0}")>-1){this.css.chart=this.css.chart.replace("{0}",this.options.theme);this.css.tooltip=this.css.tooltip.replace("{0}",this.options.theme)}},_setOption:function(key,value){this.dvWidget._setOption(key,value)},option:function(){return this.dvWidget.option.apply(this.dvWidget,arguments)},addItem:function(item){this.dataSources[this.id()].addRow(item,true)},insertItem:function(item,index){this.dataSources[this.id()].insertRow(null,item,index,true)},removeItem:function(index){this.dataSources[this.id()].deleteRow(index,true)},setItem:function(index,item){this.dataSources[this.id()].updateRow(index,item,true)},exportImage:function(width,height){return this.dvWidget._getImage(width,height,this)},destroy:function(){if(this._chart){this._chart.destroy();this._chart=null}this.dvWidget._destroy(this);$.Widget.prototype.destroy.call(this);return this},id:function(){return this.element[0].id},widget:function(){return this.element},print:function(){this.dvWidget._print()},exportVisualData:function(){return this._chart.exportVisualData()}});$.extend($.ui.igPieChart,{version:"14.2.20142.1018"})})(jQuery);