本仓库是 https://eunomia.dev/zh/tutorials/ 的学习仓库.

# 环境准备

```bash
wget https://aka.pw/bpf-ecli -O ecli && chmod +x ./ecli
wget https://github.com/eunomia-bpf/eunomia-bpf/releases/latest/download/ecc && chmod +x ./ecc
```

`bpf_printk`的输出可以在 `/sys/kernel/debug/tracing/trace_pipe` 看到，如果没有启用则可以通过`echo 1 > /sys/kernel/debug/tracing/tracing_on`启用。