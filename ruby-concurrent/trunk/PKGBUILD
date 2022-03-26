# Maintainer: Tim Meusel <tim@bastelfreak.de>
# Contributor: Christian Rebischke <chris.rebischke@archlinux.org>

_gemname='concurrent-ruby'
pkgname='ruby-concurrent'
pkgver=1.1.10
pkgrel=1
pkgdesc='Modern concurrency tools including agents, futures, promises, thread pools, actors, supervisors, and more.'
arch=('any')
url="https://github.com/ruby-concurrency/${_gemname}"
license=('MIT')
depends=('ruby')
makedepends=('ruby-rdoc')
optdepends=('java-runtime>=8: jruby support')
options=('!emptydirs')
source=("https://rubygems.org/gems/${_gemname}-${pkgver}.gem")
noextract=("${_gemname}-${pkgver}.gem")
sha512sums=('ed01d65d79e6ed2987321f4665cb5f7c3fcd701029a33e68da0feb0cd6cb2682cef619566a3bd0996db207becb0425d77967b66ee66d775a489b1317e78807ab')

package() {
  local _gemdir="$(ruby -e 'puts Gem.default_dir')"

  gem install --ignore-dependencies --no-user-install --install-dir "${pkgdir}${_gemdir}" --bindir "${pkgdir}/usr/bin" "${_gemname}-${pkgver}.gem"

  rm "${pkgdir}/${_gemdir}/cache/${_gemname}-${pkgver}.gem"
  install -Dm 644 "${pkgdir}${_gemdir}/gems/${_gemname}-${pkgver}/LICENSE.txt" -t "${pkgdir}/usr/share/licenses/${pkgname}"
}

# vim: ts=2 sw=2 et:
