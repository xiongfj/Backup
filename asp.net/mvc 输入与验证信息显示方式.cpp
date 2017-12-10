
<h2>添加 EasyXFunc</h2>
@using (Html.BeginForm("Create", "EasyXFunc", FormMethod.Post, new { @class = "form-horizontal", role = "form" }))
{
    @Html.AntiForgeryToken()
    //创建防伪标记
    <hr />
    @Html.ValidationSummary("", new { @class = "text-danger" })			// 所有的验证显示在一个块内
    <div class="form-group">
        @Html.LabelFor(m => m.FuncName, new { @class = "col-md-2 control-label" })
        <div class="col-md-10">
            @Html.TextBoxFor(m => m.FuncName, new { @class = "form-control" })
        </div>
    </div>
    <div class=" form-group">
        @Html.LabelFor(model => model.Description, new { @class = "col-md-2 control-label" })
        <div class=" col-md-10">
            @Html.TextBoxFor(model => model.Description, new { @class = "form-control" })
        </div>
    </div>
    <div class="form-group">
        <div class="col-md-offset-2 col-md-10">
            <input type="submit" value="添加" class="btn btn-primary" />
        </div>
    </div>
}
<div>
    @Html.ActionLink("返回用户列表", "Index")
</div>


------------------------------ 紧跟随输入框后面

@using (Html.BeginForm("Edit", "EasyXFunc", FormMethod.Post, new { @class = "form-horizontal", role = "form" }))
{
    @Html.AntiForgeryToken()
    @Html.ValidationSummary(true, "", new { @class = "text-danger" })

    <fieldset>
        <legend>EasyXFunc</legend>

            @Html.HiddenFor(model => model.ID)
            <div class="form-group">
                @Html.LabelFor(model => model.FuncName, new { @class = "col-md-2 control-label" })
                <div class="col-md-10">
                    @Html.TextBoxFor(model => model.FuncName, new { @class = "form-control" })
                    @Html.ValidationMessageFor(model => model.FuncName, "", new { @class = "text-danger" })
                </div>
            </div>

            <div class="form-group">
                @Html.LabelFor(model => model.Description, new { @class = "col-md-2 control-label" })
                <div class="col-md-10">
                    @Html.TextBoxFor(model => model.Description, new { @class = "form-control" })
                    @Html.ValidationMessageFor(model => model.Description, "", new { @class = "text-danger" })
                </div>
            </div>
            <div class="form-group">
                <div class="col-md-offset-2 col-md-10">
                    <input type="submit" class="btn btn-default" value="Save" />
                </div>
            </div>
    </fieldset>
}