# Maintainer: David Runge <dvzrv@archlinux.org>

pkgbase=cri-tools
pkgname=(
  crictl
  critest
)
pkgver=1.27.0
pkgrel=1
pkgdesc="CLI and validation tools for Kubelet Container Runtime Interface (CRI)"
arch=(x86_64)
url="https://github.com/kubernetes-sigs/cri-tools"
license=(Apache)
groups=(kubernetes-tools)
depends=(glibc)
makedepends=(go)
source=(
  https://github.com/kubernetes-sigs/cri-tools/archive/v$pkgver/$pkgbase-v$pkgver.tar.gz
  $pkgbase-1.27.0-makefile.patch
)
sha512sums=('b94122e6401eb0c33b9c3d112274b7ab20cbbad05e76a54933e79d2e42ded2d684771cb9ed703a6c1afa381844142b6f1b4dc77d17e915f9a42c236fd8426b9b'
            'd243325031c5abccfec7035575abeb4af87724a28f90e75b575dec01435deaf6ea157f75725b7bfe1f982b8353ebefb07e22103c9b2027b19d8c233651363f11')
b2sums=('d6c0429271ebc4085e75b54d7f3b9f75ab796e63bc9ae7562105296b13bbad8b512293a7d25abf1ab946f4bf54e672016fdb72696c12c730d21ac74724da465c'
        '428c8f35b61ecf9e7c261903fd5dc8b15b26a6b326a510f7b888f3d6989695e6345c98832886da5dfdc15b9087302a866c272a33cdb6f45d7698c70bcfdff1ca')

prepare() {
  # fix various issues with Makefile: https://github.com/kubernetes-sigs/cri-tools/pull/1140
  patch -Np1 -d $pkgbase-$pkgver -i ../$pkgbase-1.27.0-makefile.patch
}

build() {
  local common_ldflags=(
    -compressdwarf=false
    -linkmode external
  )

  export CGO_CPPFLAGS="$CPPFLAGS"
  export CGO_CFLAGS="$CFLAGS"
  export CGO_CXXFLAGS="$CXXFLAGS"
  export CGO_LDFLAGS="$LDFLAGS"
  export CGO_ENABLED=1
  export GOPATH="${srcdir}"
  export GOFLAGS="-buildmode=pie -mod=readonly -modcacherw"

  make VERSION=$pkgver GO_LDFLAGS="${common_ldflags[*]}" -C $pkgbase-$pkgver

  mkdir -vp completions
  $pkgbase-$pkgver/build/bin/linux/amd64/crictl completion bash > completions/crictl
  $pkgbase-$pkgver/build/bin/linux/amd64/crictl completion zsh > completions/_crictl
  $pkgbase-$pkgver/build/bin/linux/amd64/crictl completion fish > completions/crictl.fish
}

package_crictl() {
  pkgdesc="A CLI for CRI-compatible container runtimes"

  install -vDm 755 $pkgbase-$pkgver/build/bin/linux/amd64/$pkgname -t "$pkgdir/usr/bin/"
  # shell completion
  install -vDm 644 completions/$pkgname -t "$pkgdir/usr/share/bash-completion/completions/"
  install -vDm 644 completions/_$pkgname -t "$pkgdir/usr/share/zsh/site-functions/"
  install -vDm 644 completions/$pkgname.fish -t "$pkgdir/usr/share/fish/completions/"
  # docs
  install -vDm 644 $pkgbase-$pkgver/docs/$pkgname.md -t "$pkgdir/usr/share/doc/$pkgname/"
  install -vDm 644 $pkgbase-$pkgver/docs/examples/*.{json,yaml} -t "$pkgdir/usr/share/doc/$pkgname/examples/"
  install -vDm 644 $pkgbase-$pkgver/{{CHANGELOG,CONTRIBUTING,README,code-of-conduct}.md,SECURITY_CONTACTS} -t "$pkgdir/usr/share/doc/$pkgname"
}

package_critest() {
  pkgdesc="A benchmarking CLI for CRI-compatible container runtimes"

  install -vDm 755 $pkgbase-$pkgver/build/bin/linux/amd64/$pkgname -t "$pkgdir/usr/bin/"
  # docs
  install -vDm 644 $pkgbase-$pkgver/docs/{benchmark,validation}.md -t "$pkgdir/usr/share/doc/$pkgname/"
  install -vDm 644 $pkgbase-$pkgver/{{CHANGELOG,CONTRIBUTING,README,code-of-conduct}.md,SECURITY_CONTACTS} -t "$pkgdir/usr/share/doc/$pkgname/"
}
