
index.cshtml
-------------------------

@using Webdiyer.WebControls.Mvc
@model IEnumerable<MainTain.Models.EasyXFuncEditViewModel>

@{
    ViewBag.Title = "EasyXFunc Setting";
}
<h2>EasyXFunc �б�</h2>

@Html.ActionLink("�½�������", "Create")
<fieldset>
    @using (Ajax.BeginForm("AjaxSearchPost",
                                new RouteValueDictionary {
                                    { "id", "" }			// ��action����id
                                },
                                new AjaxOptions
                                {
                                    UpdateTargetId = "views",
                                    InsertionMode = InsertionMode.Replace
                                },
                                new RouteValueDictionary {
                                    { "id", "searchForm" },		// ��css����
                                    { "class", "form-inline well well-sm" }
                                }
                           )
             )
    {
        <span>FuncName: </span>
        <input type="text" name="FuncName" placeholder="as: line" data-toggle="tooltip" id="FuncName" style="width: 170px" class="form-control" />
        <input type="submit" value="����(S)" accesskey="S" class="btn btn-default" />
    }
</fieldset>
<div id="views">
    @Html.Partial("_AjaxSearchPost", Model)
</div>
@section Scripts
{
    @{Html.RegisterMvcPagerScriptResource();}
}

---------------------------
AjaxSearchPost action:
---------

		[HttpPost]
		public ActionResult AjaxSearchPost(string FuncName, int id = 1)
		{
			return ajaxSearchPostResult(FuncName, id);
		}
		private ActionResult ajaxSearchPostResult(string FuncName, int id = 1)
		{
			var qry = _mDB.mEasyXFunc.GetList().AsQueryable();
			if (!string.IsNullOrWhiteSpace(FuncName))
				qry = qry.Where(a => a.FuncName.ToLower().Contains(FuncName.ToLower()));

			var model = Mapper.Map<IList<EasyXFuncEditViewModel>>(qry).ToPagedList(id, 10);
			if (Request.IsAjaxRequest())
				return PartialView("_AjaxSearchPost", model);
			return View(model);
		}













