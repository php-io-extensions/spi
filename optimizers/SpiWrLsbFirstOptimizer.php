<?php

namespace Zephir\Optimizers\FunctionCall;

use Zephir\Call;
use Zephir\CompilationContext;
use Zephir\CompiledExpression;
use Zephir\Exception\CompilerException;
use Zephir\Optimizers\OptimizerAbstract;

class SpiWrLsbFirstOptimizer extends OptimizerAbstract
{
    public function optimize(array $expression, Call $call, CompilationContext $context)
    {
        if (!isset($expression['parameters']) || count($expression['parameters']) !== 2) {
            throw new CompilerException("'spi_wr_lsb_first' requires exactly two parameters", $expression);
        }

        $context->headersManager->add('api/spi-write');

        $resolvedParams = $call->getReadOnlyResolvedParams($expression['parameters'], $context, $expression);

        return new CompiledExpression(
            'long',
            'spi_wr_lsb_first(' . $resolvedParams[0] . ', ' . $resolvedParams[1] . ')',
            $expression
        );
    }
}
