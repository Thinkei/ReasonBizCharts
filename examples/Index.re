module App = {
  let component = ReasonReact.statelessComponent("app");
  let make = _children => {...component, render: _self => <Thermal />};
};

ReactDOMRe.renderToElementWithId(<App />, "root");
