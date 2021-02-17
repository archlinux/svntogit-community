# Maintainer: David Runge <dvzrv@archlinux.org>

pkgbase=cri-tools
pkgname=('crictl' 'critest')
pkgver=1.20.0
_commit='ec9e336fd8c21c4bab89a6aed2c4a138c8cfae75' # v1.20.0
pkgrel=1
pkgdesc="CLI and validation tools for Kubelet Container Runtime Interface (CRI)"
arch=('x86_64')
url="https://github.com/kubernetes-sigs/cri-tools"
license=('Apache')
groups=('kubernetes-tools')
depends=('glibc')
makedepends=('git' 'go')
# can only build from git: https://github.com/kubernetes-sigs/cri-tools/issues/676
source=("git+https://github.com/kubernetes-sigs/${pkgbase}#commit=${_commit}"
        "${pkgbase}-1.19.0-makefile.patch"
)
sha512sums=('SKIP'
            'db51a5228b2ca0dcfe493a7178d4318b831e13c8461a68cc6239ab4ee717773b8955d2d86312bc518d4b4552289679ce71fac8961f29bb8b9d6ad5eba9332e75')
b2sums=('SKIP'
        'b26bde7934ecd79b7afa18fdd2438451893a4d298aaad4d20d2361b4ef92601b2fab79145681ae6044561ef340a22dcc83cfb091feb0e9ca4900e944224c2f10')

prepare() {
  cd "${pkgbase}"
  # set CGO_ENABLED, honor GOFLAGS and allow adding to GO_LDFLAGS
  patch -Np1 -i ../"${pkgbase}-1.19.0-makefile.patch"
}

build() {
  cd "$pkgbase"
  export CGO_CPPFLAGS="${CPPFLAGS}"
  export CGO_CFLAGS="${CFLAGS}"
  export CGO_CXXFLAGS="${CXXFLAGS}"
  export CGO_LDFLAGS="${LDFLAGS}"
  export GOFLAGS="-buildmode=pie -trimpath -ldflags=-linkmode=external -mod=readonly -modcacherw"
  # NOTE: this ensures the binaries have full RELRO
  export GO_LDFLAGS="-linkmode=external"

  make

  # crictl shell completion
  mkdir -v _output/completions
  local _binary
  for _binary in crictl; do
    "_output/${_binary}" completion bash > "_output/completions/${_binary}"
    "_output/${_binary}" completion zsh > "_output/completions/_${_binary}"
  done
}

package_crictl() {
  pkgdesc="A CLI for CRI-compatible container runtimes"

  cd "$pkgbase"
  make install-crictl BINDIR="${pkgdir}/usr/bin/"
  # shell completion
  install -vDm 644 "_output/completions/${pkgname}" -t "$pkgdir/usr/share/bash-completion/completions/"
  install -vDm 644 "_output/completions/_${pkgname}" -t "$pkgdir/usr/share/zsh/site-functions/"
  # docs
  install -vDm 644 "docs/${pkgname}.md" -t "${pkgdir}/usr/share/doc/${pkgname}/"
  install -vDm 644 docs/examples/*.{json,yaml} -t "${pkgdir}/usr/share/doc/${pkgname}/examples/"
  install -vDm 644 {{CHANGELOG,CONTRIBUTING,README,code-of-conduct}.md,SECURITY_CONTACTS} \
    -t "${pkgdir}/usr/share/doc/${pkgname}"
}

package_critest() {
  pkgdesc="A benchmarking CLI for CRI-compatible container runtimes"

  cd "$pkgbase"
  make install-critest BINDIR="${pkgdir}/usr/bin/"
  # docs
  install -vDm 644 docs/{benchmark,validation}.md -t "${pkgdir}/usr/share/doc/${pkgname}/"
  install -vDm 644 {{CHANGELOG,CONTRIBUTING,README,code-of-conduct}.md,SECURITY_CONTACTS} \
    -t "${pkgdir}/usr/share/doc/${pkgname}"
}
