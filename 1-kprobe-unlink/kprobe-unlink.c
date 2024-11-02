#include "vmlinux.h"
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>
#include <bpf/bpf_core_read.h>

char LICENSE[] SEC("license") = "Dual BSD/GPL";


SEC("kprobe/do_unlinkat")
int BPF_KPROBE(do_unlinkat, int dfd, struct filename * pathname)
{
	pid_t pid;
    const char *name;
    pid = bpf_get_current_pid_tgid() >> 32;
    name = BPF_CORE_READ(pathname, name);
    bpf_printk("KPROBE ENTRY: pid %d unlink %s\n", pid, name);
	return 0;
}

SEC ("kretprobe/do_unlinkat")
int BPF_KRETPROBE(do_unlinkat_ret, long ret)
{
    // long ret 捕获的是 do_unlinkat 函数的返回值
	pid_t pid;
    pid = bpf_get_current_pid_tgid() >> 32;
    bpf_printk("KPROBE EXIT: pid %d unlink ret %ld\n", pid, ret);
	return 0;
}