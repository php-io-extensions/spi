<?php

namespace Zephir\Optimizers\FunctionCall;

use Zephir\Call;
use Zephir\CompilationContext;
use Zephir\CompiledExpression;
use Zephir\Exception\CompilerException;
use Zephir\Optimizers\OptimizerAbstract;

class SpiReadOptimizer extends OptimizerAbstract
{
    public function optimize(array $expression, Call $call, CompilationContext $context)
    {
        if (!isset($expression['parameters']) || count($expression['parameters']) !== 2) {
            throw new CompilerException("'spi_read' requires exactly two parameters", $expression);
        }

        [$symbolVariable, $resolvedParams, $symbol] = $this->processStringOptimizer(
            $call,
            $context,
            $expression
        );

        $context->headersManager->add('api/spi-read');

        $context->codePrinter->output(
            'spi_read(' . $symbol . ', ' . $resolvedParams[0] . ', ' . $resolvedParams[1] . ');'
        );

        return new CompiledExpression('variable', $symbolVariable->getRealName(), $expression);
    }
}
