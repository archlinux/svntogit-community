# Maintainer: Jiachen Yang <farseerfc@gmail.com>
# AUR Maintainer: Swift Geek
# AUR Maintainer: Timothée Ravier <tim@siosm.fr>
# AUR Maintainer: Stefan Tatschner <rumpelsepp@sevenbyte.org>
# Contributor: Swift Geek
# Contributor: Pablo Olmos de Aguilera C. pablo+aur at odac dot co

_pkgname="powerline"
pkgbase="powerline"
pkgname=("powerline" "python-powerline" "powerline-common" "powerline-vim" "powerline-fonts")
pkgdesc='Statusline plugin for vim, and provides statuslines and prompts for several other applications, including zsh, bash, tmux, IPython, Awesome, i3 and Qtile'
pkgver=2.8.3
pkgrel=2
url="https://github.com/${_pkgname}/${_pkgname}"
license=('MIT')
arch=('x86_64')
makedepends=(
    'python-setuptools'
    'python-sphinx'
    'git'
    )
checkdepends=(
    'python-pexpect'
    'python-tox'
)
source=("${_pkgname}-${pkgver}.tar.gz::https://github.com/${_pkgname}/${_pkgname}/archive/${pkgver}.tar.gz"
        "fail-on-binary-error.patch"
        "https://github.com/powerline/powerline/commit/50d73bfb.patch")
sha512sums=('fe0301d8a64827825ed5a1c9c91066299c198bc03d949e01241fa750d892a7f86029ab777ac991dfebf05d7a163a3fdd7cd44e2dea862562bc219c3566891455'
            'd8f77a55d6056353e05556b283840e65bc0411890b5906deaf7f041843a17b08b6975ec399810e10d333384d840e66c1125f6851559e4806a850502c685a6621'
            '506cce7894a5634f8365cf55c09fec3031ee58f7620730213a9032195482b3adae278402198920e6918851a8f34e451b19b3176d7cd29c31bf195214886f9fcd')



prepare() {
    # fix https://bugs.archlinux.org/task/48358
    cd "${srcdir}/${_pkgname}-${pkgver}"
    find scripts -type f -iname "powerline-*" -print0 | xargs -0 sed -i "1s/env //"
    find "${_pkgname}"/bindings -type f -iname "*.py" -print0 | xargs -0 sed -i "1s/env //"

    # explicitly fail if building binary usr/bin/powerline has any error
    patch -N <../fail-on-binary-error.patch
    # Fix build with python 3.11
    patch -p1 -i ../50d73bfb.patch
}

build(){
    # build main pages
    cd "${srcdir}/${_pkgname}-${pkgver}/docs"
    make man

    # build C client
    cd "${srcdir}/${_pkgname}-${pkgver}"
    LC_ALL=C python setup.py build
}


# FIXME Currently test will fail with dividers and other errors
check(){
    cd "${srcdir}/${_pkgname}-${pkgver}"
    LC_ALL=C python setup.py test
}

package_powerline(){
    depends=('python-powerline')
    conflicts=('python-powerline<=2.3-1')
    replaces=('python-powerline<=2.3-1')

    cd "${srcdir}/${_pkgname}-${pkgver}/scripts"
    install -Dm755 powerline "${pkgdir}/usr/bin/powerline"
    install -Dm755 powerline-config "${pkgdir}/usr/bin/powerline-config"
    install -Dm755 powerline-daemon "${pkgdir}/usr/bin/powerline-daemon"
    install -Dm755 powerline-lint "${pkgdir}/usr/bin/powerline-lint"
    install -Dm755 powerline-render "${pkgdir}/usr/bin/powerline-render"
    
    install -dm755 "${pkgdir}/usr/share/powerline/"
    ln -s "$(python3 -c 'import site; print(site.getsitepackages()[0])')/powerline/bindings" "${pkgdir}/usr/share/powerline/bindings"

    # install systemd user service
    # see https://github.com/powerline/powerline/issues/1447
    # and https://bugs.archlinux.org/task/65781
    cd "${srcdir}/${_pkgname}-${pkgver}/powerline/dist/systemd"
    install -Dm644 powerline-daemon.service  "${pkgdir}/usr/lib/systemd/user/powerline-daemon.service"
    # license is installed by powerline-common
}

package_python-powerline() {
    pkgdesc='python library for powerline'
    depends=('python>=3.2' 'powerline-common')
    optdepends=('python-psutil: improved system information'
                'python-pygit2: improved git support'
                'powerline-vim: vim plugin'
                'powerline-fonts: patched fonts for powerline'
                'which: fish bindings'
                )

    # install by redirect scripts and binaries
    cd "${srcdir}/${_pkgname}-${pkgver}"
    python setup.py install --skip-build --root="${pkgdir}" --install-data=tmp --install-scripts=tmp --optimize=1
    # remove redirected scripts and binaries
    rm -rf "${pkgdir}/tmp" 

    install -dm755 "${pkgdir}/usr/share/licenses/"
    ln -s "/usr/share/licenses/${_pkgname}" "${pkgdir}/usr/share/licenses/${pkgname}"
}


package_powerline-common(){
    pkgdesc='common files for python-powerline'
    
    cd "${srcdir}/${_pkgname}-${pkgver}"

    # license
    install -Dm644 "LICENSE" "${pkgdir}/usr/share/licenses/${_pkgname}/LICENSE"

    install -dm755 "${pkgdir}/usr/share/licenses/"
    ln -s "/usr/share/licenses/${_pkgname}" "${pkgdir}/usr/share/licenses/${pkgname}"

    # manpages
    install -dm755 "${pkgdir}/usr/share/man/man1/"
    install -Dm644 "${srcdir}/${_pkgname}-${pkgver}/docs/_build/man/"* \
                   "${pkgdir}/usr/share/man/man1/"
}

package_powerline-fonts() {
    pkgdesc='patched fonts for powerline'
    provides=('otf-powerline-symbols')
    depends=('powerline-common')

    cd "${srcdir}/${_pkgname}-${pkgver}"

    install -dm755 "${pkgdir}/usr/share/fontconfig/conf.default"
    install -Dm644 "font/PowerlineSymbols.otf" "${pkgdir}/usr/share/fonts/OTF/PowerlineSymbols.otf"
    install -Dm644 "font/10-powerline-symbols.conf" "${pkgdir}/usr/share/fontconfig/conf.avail/10-powerline-symbols.conf"
    ln -s "../conf.avail/10-powerline-symbols.conf" "${pkgdir}/usr/share/fontconfig/conf.default/10-powerline-symbols.conf"

    install -dm755 "${pkgdir}/usr/share/licenses/"
    ln -s "/usr/share/licenses/${_pkgname}" "${pkgdir}/usr/share/licenses/${pkgname}"
}


package_powerline-vim() {
    pkgdesc='vim plugin for powerline'
    depends=('powerline' 'powerline-common' 'vim-runtime')

    cd "${srcdir}/${_pkgname}-${pkgver}"
    install -Dm644 "powerline/bindings/vim/plugin/powerline.vim" \
                   "${pkgdir}/usr/share/vim/vimfiles/plugin/powerline.vim"

    install -dm755 "${pkgdir}/usr/share/licenses/"
    ln -s "/usr/share/licenses/${_pkgname}" "${pkgdir}/usr/share/licenses/${pkgname}"
}
