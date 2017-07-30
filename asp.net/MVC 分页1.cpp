

* 控制器 
/*
public async Task<ActionResult> Index(int index = 1)
{
	...
	PageList pl = modelList.ToPagedList(index, 10);		// 
	return view(pl);
}
*/

<div id="views">

    <table class="table table-hover table-striped">
        <tr>
            <th>
                @Html.DisplayNameFor(model => model.Action)
            </th>
            <th>
                @Html.DisplayNameFor(model => model.Controller)
            </th>
            <th>
                @Html.DisplayNameFor(model => model.Description)
            </th>
            <th></th>
        </tr>

        @foreach (var item in Model)
        {
            <tr>
                <td>
                    @Html.DisplayFor(modelItem => item.Action)
                </td>
                <td>
                    @Html.DisplayFor(modelItem => item.Controller)
                </td>
                <td>
                    @Html.DisplayFor(modelItem => item.Description)
                </td>
                <td>
                    @Html.ActionLink("编辑", "Edit", new { id = item.Id }) |
                    @Html.ActionLink("详情", "Details", new { id = item.Id }) |
                    @Html.ActionLink("删除", "Delete", new { id = item.Id })
                </td>
            </tr>
        }
    </table>

@Ajax.Pager(
    Model,                      //@*MVC 页面对象的属性, 存储了 action 返回的 View内容*@
    new PagerOptions
    {
        PageIndexParameterName = "index",       //@*对应当前控制器里面 Index(int index) 的参数名*@
        ContainerTagName = "ul",
        PagerItemWrapperFormatString = "<li>{0}</li>",  //@*默认行样式*@
        CurrentPagerItemWrapperFormatString =   //@*当前行样式*@
        "<li class='active'>" +
        "<a href='#'>{0}" +
        "<span class='sr-only'>(current)" +
        "</span></a></li>"
    },
    new MvcAjaxOptions
    {
        UpdateTargetId = "views",		// 需要局部更新的那个 DOM 元素的 id
        EnablePartialLoading = true		// 启用局部加载功能
    },
    new { @class = "pagination" })		// 貌似是设置 id=views 的标签样式

</div>
	

*  // 最后需要调用分页脚本资源
@section Scripts{@{Html.RegisterMvcPagerScriptResource();}}	