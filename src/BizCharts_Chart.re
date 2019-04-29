[@bs.deriving jsConverter]
type renderer = [ | `svg | `canvas];
type scale;
type padding;
type background;
type filter;

module External = {
  [@bs.module "bizcharts"] [@react.component]
  external make:
    (
      ~renderer: string=?,
      ~forceFit: bool=?,
      ~width: int=?,
      ~height: int=?,
      ~data: array(Js.t('a))=?,
      ~scale: Js.t('b)=?,
      ~placeholder: string=?,
      /* ~padding: padding=?, */
      ~animate: bool=?,
      /* ~background: background=?, */
      /* ~plotBackground: background=?, */
      ~pixelRatio: int=?,
      /* ~filter: filter=?, */
      ~className: string=?,
      ~style: ReactDOMRe.Style.t=?,
      ~theme: string=?,
      ~children: React.element=?
    ) =>
    React.element =
    "Chart";
};

[@react.component]
let make =
    (
      ~renderer,
      ~forceFit=?,
      ~width=?,
      ~height=?,
      ~data=?,
      ~scale=?,
      ~placeholder=?,
      ~animate=?,
      ~pixelRatio=?,
      ~className=?,
      ~style=?,
      ~theme=?,
      ~children=?,
    ) =>
  <External
    renderer={rendererToJs(renderer)}
    ?forceFit
    ?width
    ?height
    ?data
    ?scale
    ?placeholder
    ?animate
    ?pixelRatio
    ?className
    ?style
    ?theme
    ?children
  />;
