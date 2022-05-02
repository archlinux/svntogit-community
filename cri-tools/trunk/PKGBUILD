# Maintainer: David Runge <dvzrv@archlinux.org>

pkgbase=cri-tools
pkgname=(crictl critest)
pkgver=1.23.0
_commit='dbe2d141dc73d0c3b7c05aafbe3d01ee2698b197'  # v1.23.0
pkgrel=2
pkgdesc="CLI and validation tools for Kubelet Container Runtime Interface (CRI)"
arch=(x86_64)
url="https://github.com/kubernetes-sigs/cri-tools"
license=(Apache)
groups=(kubernetes-tools)
depends=(glibc)
makedepends=(git go)
# can only build from git: https://github.com/kubernetes-sigs/cri-tools/issues/676
source=(
  git+https://github.com/kubernetes-sigs/$pkgbase#commit=$_commit
  $pkgbase-1.21.0-makefile.patch
)
sha512sums=('SKIP'
            '272be756f3d2514b885e0e9db2c27d851fbea016d58502fa8f5954c6b79ebb240fdbe78577e6a07ca9d737706f0e409fac7a34c664e483359c817922ea8394c2')
b2sums=('SKIP'
        '2f6c0bb70e38ed98de5f2f80a18b1852a82e6614c6acd5a968d6bdc0d4955bb2e8b81050daf50e35a4eb3637e48e879fe0c9b4fc58b4ae3d827246a3dff82710')

prepare() {
  # set CGO_ENABLED, honor GOFLAGS and allow adding to GO_LDFLAGS
  patch -Np1 -d $pkgbase -i ../$pkgbase-1.21.0-makefile.patch
}

build() {
  export CGO_CPPFLAGS="${CPPFLAGS}"
  export CGO_CFLAGS="${CFLAGS}"
  export CGO_CXXFLAGS="${CXXFLAGS}"
  export CGO_LDFLAGS="${LDFLAGS}"
  export GOFLAGS="-buildmode=pie -trimpath -ldflags=-linkmode=external -mod=readonly -modcacherw"
  # NOTE: this ensures the binaries have full RELRO
  export GO_LDFLAGS="-linkmode=external"

  make -C $pkgbase

  # crictl shell completion
  mkdir -vp completions
  local _binary
  for _binary in crictl; do
    $pkgbase/build/bin/$_binary completion bash > completions/$_binary
    $pkgbase/build/bin/$_binary completion zsh > completions/_$_binary
  done
}

package_crictl() {
  pkgdesc="A CLI for CRI-compatible container runtimes"

  install -vDm 755 $pkgbase/build/bin/$pkgname -t "$pkgdir/usr/bin/"
  # shell completion
  install -vDm 644 completions/$pkgname -t "$pkgdir/usr/share/bash-completion/completions/"
  install -vDm 644 completions/_$pkgname -t "$pkgdir/usr/share/zsh/site-functions/"
  # docs
  install -vDm 644 $pkgbase/docs/$pkgname.md -t "$pkgdir/usr/share/doc/$pkgname/"
  install -vDm 644 $pkgbase/docs/examples/*.{json,yaml} -t "$pkgdir/usr/share/doc/$pkgname/examples/"
  install -vDm 644 $pkgbase/{{CHANGELOG,CONTRIBUTING,README,code-of-conduct}.md,SECURITY_CONTACTS} -t "$pkgdir/usr/share/doc/$pkgname"
}

package_critest() {
  pkgdesc="A benchmarking CLI for CRI-compatible container runtimes"

  install -vDm 755 $pkgbase/build/bin/$pkgname -t "$pkgdir/usr/bin/"
  # docs
  install -vDm 644 $pkgbase/docs/{benchmark,validation}.md -t "$pkgdir/usr/share/doc/$pkgname/"
  install -vDm 644 $pkgbase/{{CHANGELOG,CONTRIBUTING,README,code-of-conduct}.md,SECURITY_CONTACTS} -t "$pkgdir/usr/share/doc/$pkgname/"
}
