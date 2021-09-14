# Maintainer: Tim Meusel <tim@bastelfreak.de>

_gemname='scanf'
pkgname="ruby-${_gemname}"
pkgver=1.0.0
pkgrel=1
pkgdesc='A implementation of the C function scanf(3).'
arch=('any')
url="https://github.com/ruby/${_gemname}"
license=('BSD-2-Clause')
makedepends=('ruby-rdoc' 'ruby-rake' 'ruby-bundler')
checkdepends=('ruby-test-unit')
options=('!emptydirs')
source=("${url}/archive/v${pkgver}/${_gemname}-v${pkgver}.tar.gz")
sha512sums=('608833c45d43f2ef1043bb584c3f8186399f8c03ecc1ab21e23f240203830e9372019a399f39a658199b0938c39fcbcb6f83e4994441488f3646ca75b59537cd')

prepare() {
  cd "${srcdir}/${_gemname}-${pkgver}"

}

build() {
  cd "${srcdir}/${_gemname}-${pkgver}"
  gem build "${_gemname}.gemspec"
}

check() {
  cd "${srcdir}/${_gemname}-${pkgver}"
  rake test
}

package() {
cd "${srcdir}/${_gemname}-${pkgver}"
  local _gemdir="$(gem env gemdir)"
  gem install --verbose --ignore-dependencies --no-user-install --install-dir "${pkgdir}/${_gemdir}" --bindir "${pkgdir}/usr/bin" "${_gemname}-${pkgver}.gem"

  install -Dm 644 LICENSE.txt -t "${pkgdir}/usr/share/licenses/${pkgname}/"

  install -Dm 644 README.md -t "${pkgdir}/usr/share/doc/${pkgname}"

  rm -rf "${pkgdir}/${_gemdir}/cache"
}
