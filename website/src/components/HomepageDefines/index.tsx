import CodeBlock from '@theme/CodeBlock';
import Heading from '@theme/Heading';

const defines = 
`#if !defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED
#endif // !defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

#if !defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
// #define MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED
#endif // !defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)

#if !defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
// #define MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
#endif // !defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
`;

export default function HomepageDefines(): JSX.Element {
  return (
    <section className="container margin-vert--lg">
      <Heading as="h2" className="text--center">Configuration macro definitions</Heading>
      <div className="row" style={{justifyContent: 'center'}}>
        <CodeBlock language="cpp" title="include/micro-os-plus/micro-test-plus-defines.h">{defines}</CodeBlock>
      </div>
    </section>
  );
}
