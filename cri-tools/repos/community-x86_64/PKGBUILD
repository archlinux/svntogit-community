# Maintainer: David Runge <dvzrv@archlinux.org>

pkgbase=cri-tools
pkgname=('crictl' 'critest')
pkgver=1.22.0
_commit='d82b602a7282356d4f675735a3ed4595fc7d73ce' # v1.22.0
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
        "${pkgbase}-1.21.0-makefile.patch"
)
sha512sums=('SKIP'
            '272be756f3d2514b885e0e9db2c27d851fbea016d58502fa8f5954c6b79ebb240fdbe78577e6a07ca9d737706f0e409fac7a34c664e483359c817922ea8394c2')
b2sums=('SKIP'
        '2f6c0bb70e38ed98de5f2f80a18b1852a82e6614c6acd5a968d6bdc0d4955bb2e8b81050daf50e35a4eb3637e48e879fe0c9b4fc58b4ae3d827246a3dff82710')

prepare() {
  cd "${pkgbase}"
  # set CGO_ENABLED, honor GOFLAGS and allow adding to GO_LDFLAGS
  patch -Np1 -i ../"${pkgbase}-1.21.0-makefile.patch"
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
  mkdir -vp build/completions
  local _binary
  for _binary in crictl; do
    "build/bin/${_binary}" completion bash > "build/completions/${_binary}"
    "build/bin/${_binary}" completion zsh > "build/completions/_${_binary}"
  done
}

package_crictl() {
  pkgdesc="A CLI for CRI-compatible container runtimes"

  cd "$pkgbase"
  install -vDm 755 "build/bin/${pkgname}" -t "${pkgdir}/usr/bin"
  # shell completion
  install -vDm 644 "build/completions/${pkgname}" -t "$pkgdir/usr/share/bash-completion/completions/"
  install -vDm 644 "build/completions/_${pkgname}" -t "$pkgdir/usr/share/zsh/site-functions/"
  # docs
  install -vDm 644 "docs/${pkgname}.md" -t "${pkgdir}/usr/share/doc/${pkgname}/"
  install -vDm 644 docs/examples/*.{json,yaml} -t "${pkgdir}/usr/share/doc/${pkgname}/examples/"
  install -vDm 644 {{CHANGELOG,CONTRIBUTING,README,code-of-conduct}.md,SECURITY_CONTACTS} \
    -t "${pkgdir}/usr/share/doc/${pkgname}"
}

package_critest() {
  pkgdesc="A benchmarking CLI for CRI-compatible container runtimes"

  cd "$pkgbase"
  install -vDm 755 "build/bin/${pkgname}" -t "${pkgdir}/usr/bin"
  # docs
  install -vDm 644 docs/{benchmark,validation}.md -t "${pkgdir}/usr/share/doc/${pkgname}/"
  install -vDm 644 {{CHANGELOG,CONTRIBUTING,README,code-of-conduct}.md,SECURITY_CONTACTS} \
    -t "${pkgdir}/usr/share/doc/${pkgname}"
}
