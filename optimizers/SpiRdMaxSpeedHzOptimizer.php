<?php

namespace Zephir\Optimizers\FunctionCall;

use Zephir\Call;
use Zephir\CompilationContext;
use Zephir\CompiledExpression;
use Zephir\Exception\CompilerException;
use Zephir\Optimizers\OptimizerAbstract;

class SpiRdMaxSpeedHzOptimizer extends OptimizerAbstract
{
    public function optimize(array $expression, Call $call, CompilationContext $context)
    {
        if (!isset($expression['parameters']) || count($expression['parameters']) !== 1) {
            throw new CompilerException("'spi_rd_max_speed_hz' requires exactly one parameter", $expression);
        }

        $context->headersManager->add('api/spi-read');

        $resolvedParams = $call->getReadOnlyResolvedParams($expression['parameters'], $context, $expression);

        return new CompiledExpression(
            'long',
            'spi_rd_max_speed_hz(' . $resolvedParams[0] . ')',
            $expression
        );
    }
}
