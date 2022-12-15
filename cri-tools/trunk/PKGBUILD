# Maintainer: David Runge <dvzrv@archlinux.org>

pkgbase=cri-tools
pkgname=(crictl critest)
pkgver=1.26.0
_commit=cf1c8287fcef4444226e54482bf3827e8f804421  # v1.26.0
pkgrel=1
pkgdesc="CLI and validation tools for Kubelet Container Runtime Interface (CRI)"
arch=(x86_64)
url="https://github.com/kubernetes-sigs/cri-tools"
license=(Apache)
groups=(kubernetes-tools)
depends=(glibc)
makedepends=(git go)
options=(debug)
# can only build from git: https://github.com/kubernetes-sigs/cri-tools/issues/676
source=(
  git+https://github.com/kubernetes-sigs/$pkgbase#commit=$_commit
  $pkgbase-1.24.1-makefile.patch
)
sha512sums=('SKIP'
            'b3c47dfd7a624faecc94627dbcb6279af6927a5c4bd470b244619b2dc24b1afc2a3378491583686e0c763c98191d1f2122afa75cdf9c4f4a7a70e344f5c7e5a4')
b2sums=('SKIP'
        '51e53be22879437df77507c1157a80081cfd5db12ecd3f24e3ed7d4f421e79ad8c48347ba3e2888e896b2cbb658a13f61bbbe123e4ed34ef315864e5eef9ca85')

prepare() {
  # set CGO_ENABLED, honor GOFLAGS and allow adding to GO_LDFLAGS
  patch -Np1 -d $pkgbase -i ../$pkgbase-1.24.1-makefile.patch
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
