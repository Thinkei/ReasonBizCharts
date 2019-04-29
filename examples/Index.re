module App = {
  [@react.component]
  let make = () => <Thermal />;
};

ReactDOMRe.renderToElementWithId(<App />, "root");
