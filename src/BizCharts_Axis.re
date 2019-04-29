[@bs.deriving jsConverter]
type position = [ | `top | `right | `bottom | `left];

module TitleProp = {
  type t;

  external bool: bool => t = "%identity";
  external obj: Js.t('a) => t = "%identity";
  external null: Js.Nullable.t('b) => t = "%identity";
};

[@bs.module "bizcharts"] [@react.component]
external make:
  (
    ~name: string,
    ~visible: bool=?,
    ~position: position=?,
    ~title: TitleProp.t=?,
    ~line: Js.t('a)=?,
    ~tickLine: Js.t('b)=?,
    ~label: Js.t('c)=?,
    ~grid: Js.t('d)=?,
    ~subTickCount: int=?,
    ~subTickLine: Js.t('e)=?
  ) =>
  React.element =
  "Axis";
